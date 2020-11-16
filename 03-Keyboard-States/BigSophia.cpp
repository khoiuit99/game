#include "BigSophia.h"
#include "BigSophiaIdleState.h"
#include "BigSophiaRunningHorizontalState.h"
#include "BigSophiaRunningBottoTopState.h"
#include "BigSophiaRunningToptoBotState.h"
#include "DirectInput.h"
#include "BigSophiaState.h"
#include "Debug.h"

BigSophia* BigSophia::instance = NULL;

BigSophia* BigSophia::GetInstance()
{
	if (!instance)
	{
		instance = new BigSophia();
	}
	return instance;
}

void BigSophia::Release()
{
	delete instance;
}

BigSophia::BigSophia() :Entity()
{
	this->SetAliveState(Entity::Alive_State::Alive);

	Animation* idle = new Animation(BigSophiaState::NameState::idle, L"textures//Idle1.png", D3DCOLOR_XRGB(255, 0, 255), 1);
	Animation* runningHorizontal = new Animation(BigSophiaState::NameState::runningHorizontal, L"textures//s6.png", D3DCOLOR_XRGB(255, 0, 255), 3);
	Animation* runningBottoTop = new Animation(BigSophiaState::NameState::runningBottoTop, L"textures//s5.png", D3DCOLOR_XRGB(255, 0, 255), 3);
	Animation* runningToptoBop = new Animation(BigSophiaState::NameState::runningToptoBot, L"textures//s5m.png", D3DCOLOR_XRGB(255, 0, 255), 3);
	
	runningHorizontal->SetTime(0.1f);
	runningToptoBop->SetTime(0.1f);
	runningBottoTop->SetTime(0.1f);

	this->animations[BigSophiaState::idle] = idle;
	this->animations[BigSophiaState::runningToptoBot] = runningToptoBop;
	this->animations[BigSophiaState::runningBottoTop] = runningBottoTop;
	this->animations[BigSophiaState::runningHorizontal] = runningHorizontal;

	// other
	this->animation = this->animations[current_state];
	this->previous_state = 0;
	this->i = 0;
}

BigSophia::~BigSophia()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->animations[i];
	}
}

void BigSophia::Update(float dt)
{
	Entity::Update(dt);
	this->player_state->Update(dt);
}

void BigSophia::Draw()
{
	BigSophia* sophia = BigSophia::GetInstance();

	if (sophia->GetMoveHorizontalDirection())
	{
		sophia->GetCurrentAnimation()->SetScale(1, 1);
	}
	else {
		sophia->GetCurrentAnimation()->SetScale(-1, 1);
	}

	this->animation->Draw(Entity::position);
}

void BigSophia::HandleInput(float dt)
{
	this->player_state->HandleInput(dt);
}

void BigSophia::Init()
{
	this->player_state = new BigSophiaIdleState();
}

void BigSophia::ChangeState(BigSophiaState *new_state)
{
	delete this->player_state;
	player_state = new_state;
	this->current_state = player_state->GetCurrentState();
	this->SetCurrentAnimation(this->animations[current_state]);
}

BigSophiaState::NameState BigSophia::GetCurrentState()
{
	return this->current_state;
}

BigSophiaState* BigSophia::GetPlayerState()
{
	return this->player_state;
}

void BigSophia::SetCurrentState(BigSophiaState::NameState new_state)
{
	this->current_state = new_state;
}

void BigSophia::SetCurrentAnimation(Animation* animation)
{
	this->previous_state = this->animation->GetName();
	this->animation = animation;
}

Animation* BigSophia::GetCurrentAnimation()
{
	return this->animation;
}

Animation* BigSophia::GetAnimation(BigSophiaState::NameState state)
{
	return this->animations[state];
}

int BigSophia::GetPreviousState()
{
	return this->previous_state;
}


void BigSophia::AddTimeBuffer(float dt)
{
	this->time_buffer += dt;
}

float BigSophia::GetTimeBuffer()
{
	return this->time_buffer;
}

void BigSophia::SetTimeBuffer(float dt)
{
	this->time_buffer = dt;
}


D3DXVECTOR2 BigSophia::GetPositionIdle()
{
	return this->position_idle;
}
