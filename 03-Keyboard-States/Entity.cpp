#include <d3dx9.h>
#include "Debug.h"
#include "GameManager.h"
#include "Entity.h"
#include "Sprite.h"

Entity::Entity()
{
	this->velocity.x = 0;
	this->velocity.y = 0;
}
Entity::~Entity()
{
}

void Entity::SetAliveState(Alive_State _alive)
{
	this->aliveState = _alive;
}

void Entity::SetVelocity(float x, float y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

void Entity::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void Entity::SetPosition(D3DXVECTOR2 position)
{
	this->position = position;
}

D3DXVECTOR2 Entity::GetPosition()
{
	return this->position;
}

D3DXVECTOR2 Entity::GetVelocity()
{
	return this->velocity;
}

float Entity::GetVelocityX()
{
	return this->velocity.x;
}

float Entity::GetVelocityY()
{
	return this->velocity.y;
}

void Entity::SetPositionX(float x)
{
	this->position.x = x;
}

void Entity::SetPositionY(float y)
{
	this->position.y = y;
}

void Entity::SetVelocity(D3DXVECTOR2 _velocity)
{
}

void Entity::SetVelocityX(float x)
{
	this->velocity.x = x;
}

void Entity::SetVelocityY(float y)
{
	this->velocity.y = y;
}

void Entity::AddVelocityX(float dx)
{
	this->velocity.x += dx;
}

void Entity::AddVelocityY(float dy)
{
	this->velocity.y += dy;
}

void Entity::SetSize(const SIZE& size)
{
	this->size = size;
}

void Entity::SetSize(long width, long height)
{
	this->size.cx = width;
	this->size.cy = height;
}

SIZE Entity::GetSize()
{
	return size;
}

void Entity::SetMoveHorizontalDirection(Entity_Horizontal_Direction _horizontalDirection)
{
	this->horizontal_Direction = _horizontalDirection;
}

Entity::Entity_Horizontal_Direction Entity::GetMoveHorizontalDirection()
{
	return this->horizontal_Direction;
}

void Entity::SetMoveVerticalDirection(Entity_Vertical_Direction _verticalDirection)
{
	this->vertical_Direction = _verticalDirection;
}

Entity::Entity_Vertical_Direction Entity::GetMoveVerticalDirection()
{
	return this->vertical_Direction;
}

void Entity::SetJumpDirection(Entity_Jump_Direction _jumpDirection)
{
	this->jump_Direction = _jumpDirection;
}

Entity::Entity_Jump_Direction Entity::GetJumpDirection()
{
	return this->jump_Direction;
}

void Entity::Update(float dt)
{

	if (this->horizontal_Direction == Entity::Entity_Horizontal_Direction::LeftToRight) {
		this->velocity.x = fabs(this->GetVelocityX());
	}
	else {
		this->velocity.x = -fabs(this->GetVelocityX());
	}

	if (this->vertical_Direction == Entity::Entity_Vertical_Direction::BotToTop1) {
		this->velocity.y = fabs(this->GetVelocityY());
	}
	else {
		this->velocity.y = -fabs(this->GetVelocityY());
	}

	this->position.x += this->velocity.x * dt;
	this->position.y += this->velocity.y * dt;
}