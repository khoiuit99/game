#include "GameManager.h"
#include "GameTimer.h"
#include "Debug.h"
#include "d3d.h"
#include "DirectInput.h"
#include "Texture.h"
#include "Sprite.h"
#include "BigSophia.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningBottoTopState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "GameSetting.h"

DWORD GameManager::StTime = GetTickCount();

GameManager* GameManager::Instance = NULL;
int GameManager::TotalFrame = 0;
float GameManager::delta = 0.0f;

GameManager* GameManager::GetInstance()
{
	if (!Instance)
		Instance = new GameManager();
	return Instance;
}



void GameManager::Init(int fps)
{
	FPS = fps;
	TPF = 1.0f / fps; // 1.0f / fps;

	BigSophia* sophia = BigSophia::GetInstance();

	sophia->Init();
	sophia->SetPosition(50.0f, 100.0f);

}

int GameManager::GetFPS()
{
	return FPS;
}

void GameManager::Running()
{
	delta += GameTimer::GetInstance()->GetCounter();

	if (GetTickCount64() - StTime > 1000)
	{
		Debug::PrintOut(L"FPS: %d\n", TotalFrame);
		TotalFrame = 0;
		StTime = GetTickCount64();
	}

	if (delta >= TPF)
	{
		Update(delta);
		delta = 0;
	}
	else
	{
		Sleep((DWORD)((TPF - delta) * 900));
		delta = TPF;
	}

	Render();
}

void GameManager::Release()
{
	delete Instance;
}

GameManager::~GameManager()
{
	BigSophia::GetInstance()->Release();
	GameTimer::GetInstance()->Release();
	d3d::GetInstance()->Release();
	DirectInput::GetInstance()->Release();
	Texture::GetInstance()->Release();
}

void GameManager::Update(float delta)
{
	DirectInput::GetInstance()->KeySnapShot(delta);

	BigSophia* sophia = BigSophia::GetInstance();

	sophia->HandleInput(delta);
	sophia->Update(delta);

	sophia->GetPosition();
}

void GameManager::Render()
{
	auto d3d = d3d::GetInstance();
	auto d3ddev = d3d->GetDevice();
	auto bigsophia = BigSophia::GetInstance();
	if (d3ddev->BeginScene())
	{
		// something
		bigsophia->Draw();
		d3ddev->EndScene();
		//Debug::PrintOut(L"%d\n", ++TotalFrame);
		TotalFrame++;
	}
	d3ddev->Present(NULL, NULL, NULL, NULL);
}
