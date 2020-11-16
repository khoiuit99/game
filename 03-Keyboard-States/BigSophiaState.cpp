#include "BigSophiaState.h"
#include "BigSophia.h"

BigSophiaState::BigSophiaState()
{
	this->current_state = BigSophiaState::idle;
}

BigSophiaState::BigSophiaState(BigSophiaState::NameState current_state)
{
	this->current_state = current_state;
}

BigSophiaState::~BigSophiaState()
{
}

BigSophiaState::NameState BigSophiaState::GetCurrentState()
{
	return this->current_state;
}

void BigSophiaState::SetCurrentState(BigSophiaState::NameState current_state)
{
	this->current_state = current_state;
}


