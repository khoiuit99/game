#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include "Camera.h"

/*
Abstract class to define keyboard event handlers
*/

class GameManager
{
public:
	static GameManager* GetInstance();
	void Init(int FPS = 60);
	int GetFPS();
	void Running();
	void Release();

protected:
	Camera *cam;
private:
	GameManager() {};
	~GameManager();
	void Update(float delta);
	void Render();
	int FPS;
	float TPF;
	static GameManager* Instance;
	static float delta;

	static int TotalFrame;
	static DWORD StTime;
};


