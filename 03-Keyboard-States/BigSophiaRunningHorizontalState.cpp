#include "BigSophiaRunningBottoTopState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaIdleState.h"
#include "Debug.h"
#include "DirectInput.h"

BigSophiaRunningHorizontalState::BigSophiaRunningHorizontalState()
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->SetCurrentState(BigSophiaState::runningHorizontal);
	this->current_state = BigSophiaState::runningHorizontal;
	sophia->SetVelocityX(80.0f);
	sophia->SetSize(20, 45);
}

BigSophiaRunningHorizontalState::~BigSophiaRunningHorizontalState()
{

}


void BigSophiaRunningHorizontalState::Update(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->AddTimeBuffer(dt);
	sophia->GetCurrentAnimation()->Update(dt);
}

void BigSophiaRunningHorizontalState::Draw()
{
}

void BigSophiaRunningHorizontalState::HandleInput(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	auto keyboard = DirectInput::GetInstance();

	if (keyboard->KeyPress(DIK_RIGHT) && keyboard->KeyPress(DIK_LEFT))
	{
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	if (keyboard->KeyPress(DIK_RIGHT) && keyboard->GetLastPressKey() == DIK_RIGHT)
	{
		keyboard->ReleaseLastPressKey();
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::LeftToRight);
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	if (keyboard->KeyPress(DIK_LEFT) && keyboard->GetLastPressKey() == DIK_LEFT)
	{
		keyboard->ReleaseLastPressKey();
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::RightToLeft);
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}

	if (keyboard->KeyPress(LEFT_KEY))
	{
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::RightToLeft);
		sophia->previous_horizontal_direction = Entity::Entity_Horizontal_Direction::RightToLeft;
		return;
	}

	if (keyboard->KeyPress(RIGHT_KEY))
	{
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::LeftToRight);
		sophia->previous_horizontal_direction = Entity::Entity_Horizontal_Direction::LeftToRight;
		return;
	}

	sophia->ChangeState(new BigSophiaIdleState());
	return;
}

