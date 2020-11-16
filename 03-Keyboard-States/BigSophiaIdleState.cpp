#include "BigSophia.h"
#include "BigSophiaState.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "BigSophiaRunningBottoTopState.h"
#include "DirectInput.h"
#include "Debug.h"


BigSophiaIdleState::BigSophiaIdleState()
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->SetCurrentState(BigSophiaState::NameState::idle);
	this->current_state = BigSophiaState::NameState::idle;
	sophia->SetVelocity(0, 0);
	sophia->SetSize(20, 45);
}

BigSophiaIdleState::~BigSophiaIdleState()
{

}

void BigSophiaIdleState::Update(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->GetCurrentAnimation()->Update(dt);
	sophia->SetVelocity(0, 0);
}

void BigSophiaIdleState::Draw()
{
}

void BigSophiaIdleState::HandleInput(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	auto keyboard = DirectInput::GetInstance();

	if (keyboard->KeyDown(RIGHT_KEY) || keyboard->KeyPress(RIGHT_KEY))
	{
		//Debug::PrintOut(L"Printed");
		sophia->ChangeState(new BigSophiaRunningHorizontalState());
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::LeftToRight);
		return;
	}

	//if (keyboard->KeyDown(DOWN_KEY) || keyboard->KeyPress(DOWN_KEY))
	//{
	//	Debug::PrintOut(L"Printed");
	//	sophia->ChangeState(new BigSophiaRunningVerticalState());
	//	sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::BotToTop1);
	//	return;
	//}

	if (keyboard->KeyDown(LEFT_KEY) || keyboard->KeyPress(LEFT_KEY))
	{
		sophia->ChangeState(new BigSophiaRunningHorizontalState());
		sophia->SetMoveHorizontalDirection(Entity::Entity_Horizontal_Direction::RightToLeft);
		return;
	}

	if (keyboard->KeyDown(DOWN_KEY) || keyboard->KeyPress(DOWN_KEY))
	{
		sophia->ChangeState(new BigSophiaRunningToptoBotState());
		sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::TopToBot1);
		return;
	}

}