#include "DirectInput.h"
#include "Debug.h"

DirectInput* DirectInput::Instance = NULL;

DirectInput* DirectInput::GetInstance()
{
	if (!Instance)
		Instance = new DirectInput();
	return Instance;
}

HRESULT DirectInput::Init(HWND hWnd)
{
	HRESULT result = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, NULL);
	if (result != DI_OK)
	{
		Debug::PrintOut(L"[Error code %d] Error while create Input device!", &result);
		return result;
	}
	result = dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL);
	if (result != DI_OK)
	{
		Debug::PrintOut(L"[Error code %d] Error while create Input Keyboard!", &result);
		return result;
	}
	result = dikeyboard->SetDataFormat(&c_dfDIKeyboard);
	result = dikeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);;
	result = dikeyboard->Acquire();

	result = dinput->CreateDevice(GUID_SysMouse, &dimouse, NULL);
	if (result != DI_OK)
	{
		Debug::PrintOut(L"[Error code %d] Error while create Input Mouse!", &result);
		return result;
	}
	result = dimouse->SetDataFormat(&c_dfDIMouse);
	result = dimouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	result = dimouse->Acquire();
	if (result != DI_OK)
		Debug::PrintOut(L"[Error code %d] Error while Acquire Mouse!", &result);
	return result;
}

void DirectInput::KeySnapShot(float dt)
{

	delta += dt;
	if (delta > KEYBOARD_LAST_PRESS_TIME)
		ReleaseLastPressKey();
	for (int i = 0; i < 256; i++)
		buffer[i] = keys[i];

	HRESULT result = dikeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
	while (result != DI_OK && (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED))
	{
		//Debug::PrintOut(L"[Error code %d] Error while Acquire Keyboard!", &result);
		result = dikeyboard->Acquire();
	}
	FirstCheck = true;
}

void DirectInput::MouseSnapShot()
{
	dimouse->GetDeviceState(sizeof(mouse_state), (LPVOID)&mouse_state);
}

bool DirectInput::KeyPress(int key)
{
	if (keys[key] & 0x80)
	{
		if (FirstCheck && buffer[key] != keys[key])
		{
			BufferLastKey = LastKey;
			LastKey = key;
			delta = 0.0f;
			FirstCheck = false;
		}
		return true;
	}
	return false;
}

bool DirectInput::KeyDown(int Key)
{
	return KeyPress(Key) && !BufferCheck(Key);
}

bool DirectInput::KeyUp(int Key)
{
	return !KeyPress(Key) && BufferCheck(Key);
}

void DirectInput::Release()
{
	delete Instance;
}

int DirectInput::GetLastPressKey()
{
	return BufferLastKey;
}

void DirectInput::ReleaseLastPressKey()
{
	delta = 0.0f;
	BufferLastKey = -1;
	LastKey = -1;
}

DirectInput::~DirectInput()
{
	if (dikeyboard != NULL)
	{
		dikeyboard->Unacquire();
		dikeyboard->Release();
		dikeyboard = NULL;
	}
	if (dimouse != NULL)
	{
		dimouse->Unacquire();
		dimouse->Release();
		dimouse = NULL;
	}
	if (dinput != NULL)
		dinput->Release();
}

bool DirectInput::BufferCheck(int key)
{
	return buffer[key] & 0x80;
}
