#include "BigSophia.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaRunningBottoTopState.h"
#include "BigSophiaState.h"
#include "DirectInput.h"

BigSophiaRunningBottoTopState::BigSophiaRunningBottoTopState()
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->SetCurrentState(BigSophiaState::runningBottoTop);
	this->current_state = BigSophiaState::runningBottoTop;
	sophia->SetVelocityY(VELOCITY_Y);
	sophia->SetSize(20, 45);
}

BigSophiaRunningBottoTopState::~BigSophiaRunningBottoTopState()
{
}


void BigSophiaRunningBottoTopState::Update(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->AddTimeBuffer(dt);
	sophia->GetCurrentAnimation()->Update(dt);
}

void BigSophiaRunningBottoTopState::Draw()
{
}

void BigSophiaRunningBottoTopState::HandleInput(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	auto keyboard = DirectInput::GetInstance();

	if (keyboard->KeyPress(DIK_UP) && keyboard->KeyPress(DIK_DOWN))
	{
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	if (keyboard->KeyPress(DIK_UP) && keyboard->GetLastPressKey() == DIK_UP)
	{
		keyboard->ReleaseLastPressKey();
		sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::BotToTop1);
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	if (keyboard->KeyPress(DIK_DOWN) && keyboard->GetLastPressKey() == DIK_DOWN)
	{
		keyboard->ReleaseLastPressKey();
		sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::TopToBot1);
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	sophia->ChangeState(new BigSophiaIdleState());
	return;
}


