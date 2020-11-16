#pragma once
#include "BigSophia.h"
#include "BigSophiaState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaIdleState.h"
#include "DirectInput.h"

class BigSophiaRunningToptoBotState : public BigSophiaState
{
public:
	BigSophiaRunningToptoBotState();
	~BigSophiaRunningToptoBotState();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void HandleInput(float dt);
};
