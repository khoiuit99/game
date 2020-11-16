#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

class Entity
{
public:

	enum Entity_Horizontal_Direction {
		LeftToRight,
		RightToLeft
	};

	enum Entity_Vertical_Direction {
		BotToTop1,
		TopToBot1
	};

	enum Entity_Jump_Direction {
		BotToTop,
		TopToBot
	};

	enum Alive_State {
		Alive,
		Beaten,
		Die,
		Remove
	};

	Entity();
	~Entity();

	virtual void SetAliveState(Alive_State _alive);

	//velocity
	virtual void SetVelocity(D3DXVECTOR2 _velocity);
	virtual void SetVelocity(float x, float y);
	virtual float GetVelocityX();
	virtual void SetVelocityX(float x);
	virtual void AddVelocityX(float dx);
	virtual float GetVelocityY();
	virtual void SetVelocityY(float y);
	virtual void AddVelocityY(float dy);

	//position
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(D3DXVECTOR2 _position);
	virtual D3DXVECTOR2 GetPosition();
	virtual D3DXVECTOR2 GetVelocity();
	virtual void SetPositionX(float x);
	virtual void SetPositionY(float y);

	//direction
	virtual void SetMoveHorizontalDirection(Entity_Horizontal_Direction _horizontal_direction);
	virtual Entity_Horizontal_Direction GetMoveHorizontalDirection();
	virtual void SetMoveVerticalDirection(Entity_Vertical_Direction __vertical_direction);
	virtual Entity_Vertical_Direction GetMoveVerticalDirection();
	virtual void SetJumpDirection(Entity_Jump_Direction __jump_direction);
	virtual Entity_Jump_Direction GetJumpDirection();

	virtual void SetSize(const SIZE& size);
	virtual void SetSize(long width, long height);
	virtual SIZE GetSize();

	//other	
	virtual void Update(float dt);
	virtual void Draw() {};

protected:

	Entity_Horizontal_Direction horizontal_Direction;
	Entity_Vertical_Direction vertical_Direction;
	Entity_Jump_Direction jump_Direction;
	Alive_State aliveState;
	D3DXVECTOR2 position;
	D3DXVECTOR2 velocity;
	SIZE size;

};

