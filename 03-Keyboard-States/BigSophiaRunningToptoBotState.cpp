#include "BigSophia.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "BigSophiaState.h"
#include "DirectInput.h"

BigSophiaRunningToptoBotState::BigSophiaRunningToptoBotState()
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->SetCurrentState(BigSophiaState::runningToptoBot);
	this->current_state = BigSophiaState::runningToptoBot;
	sophia->SetVelocityY(80.0f);
	sophia->SetSize(20, 45);
}

BigSophiaRunningToptoBotState::~BigSophiaRunningToptoBotState()
{
}


void BigSophiaRunningToptoBotState::Update(float dt)
{
	BigSophia* sophia = BigSophia::GetInstance();
	sophia->AddTimeBuffer(dt);
	sophia->GetCurrentAnimation()->Update(dt);
}

void BigSophiaRunningToptoBotState::Draw()
{
}

void BigSophiaRunningToptoBotState::HandleInput(float dt)
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

	if (keyboard->KeyPress(DOWN_KEY))
	{
		sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::TopToBot1);
		sophia->previous_vertical_direction = Entity::Entity_Vertical_Direction::TopToBot1;
		return;
	}

	sophia->ChangeState(new BigSophiaIdleState());
	return;

	/*if (keyboard->KeyPress(DIK_DOWN) && keyboard->GetLastPressKey() == DIK_DOWN)
	{
		keyboard->ReleaseLastPressKey();
		sophia->SetMoveVerticalDirection(Entity::Entity_Vertical_Direction::TopToBot1);
		sophia->ChangeState(new BigSophiaIdleState());
		return;
	}*/

	/*sophia->ChangeState(new BigSophiaIdleState());
	return;*/
}


