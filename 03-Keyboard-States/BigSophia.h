#pragma once
#include "Entity.h"
#include "Animation.h"
#include "BigSophiaState.h"
#include "Sprite.h"
#include <map>

#define VELOCITY_X 80.0f
#define VELOCITY_Y 80.0f

using namespace std;

class BigSophia : public Entity
{
public:
	static BigSophia* GetInstance();
	void Release();
	void Update(float dt);
	void Draw();
	void HandleInput(float dt);
	void Init();
	// get
	BigSophiaState::NameState GetCurrentState();
	BigSophiaState* GetPlayerState();
	Animation* GetCurrentAnimation();
	Animation* GetAnimation(BigSophiaState::NameState state);
	D3DXVECTOR2 GetPositionIdle();
	Entity::Entity_Horizontal_Direction previous_horizontal_direction;
	Entity::Entity_Vertical_Direction previous_vertical_direction;
	int GetPreviousState();
	float GetTimeBuffer();
	void AddTimeBuffer(float dt);
	// set
	void ChangeState(BigSophiaState* new_state);
	void SetCurrentState(BigSophiaState::NameState new_state);
	void SetCurrentAnimation(Animation* animation);
	void SetTimeBuffer(float dt);


	float time_invisible;

	int previous_state;
	int i;

	Entity* CarrierObject;
protected:
	static BigSophia* instance;
	float time_buffer;
	std::map<int, Animation*> animations;
	BigSophiaState::NameState current_state;
	BigSophiaState* player_state;
	Animation* animation;
	D3DXVECTOR2 position_idle;
private:
	BigSophia();
	~BigSophia();
};