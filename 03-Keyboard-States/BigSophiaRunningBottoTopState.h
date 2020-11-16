#pragma once
#include "BigSophia.h"
#include "BigSophiaState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaIdleState.h"
#include "DirectInput.h"

class BigSophiaRunningBottoTopState : public BigSophiaState
{
public:
	BigSophiaRunningBottoTopState();
	~BigSophiaRunningBottoTopState();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void HandleInput(float dt);
};
