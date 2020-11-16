#pragma once
#include "Animation.h"
#include "GameManager.h"
#include "Entity.h"
#include <math.h>

#define UP_KEY DIK_UPARROW
#define DOWN_KEY DIK_DOWNARROW
#define LEFT_KEY DIK_LEFTARROW
#define RIGHT_KEY DIK_RIGHTARROW

class BigSophiaState
{
public:
	enum NameState {
		idle,
		runningHorizontal,
		runningToptoBot,
		runningBottoTop
	};
	BigSophiaState();
	BigSophiaState(BigSophiaState::NameState current_state);
	~BigSophiaState();
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void HandleInput(float dt) = 0;
	BigSophiaState::NameState GetCurrentState();
	void SetCurrentState(BigSophiaState::NameState current_state);
protected:
	BigSophiaState::NameState current_state;
};


