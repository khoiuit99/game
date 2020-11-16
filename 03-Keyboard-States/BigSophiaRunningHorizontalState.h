#pragma once
#include "BigSophiaState.h"
#include "BigSophia.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "DirectInput.h"

class BigSophiaRunningHorizontalState : public BigSophiaState
{
public:
	BigSophiaRunningHorizontalState();
	~BigSophiaRunningHorizontalState();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void HandleInput(float dt);
};
