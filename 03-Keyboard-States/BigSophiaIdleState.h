#pragma once
#include "BigSophiaState.h"
#include "BigSophia.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaRunningBottoTopState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "DirectInput.h"

class BigSophiaIdleState : public BigSophiaState
{
public:
	BigSophiaIdleState();
	~BigSophiaIdleState();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void HandleInput(float dt);
};
