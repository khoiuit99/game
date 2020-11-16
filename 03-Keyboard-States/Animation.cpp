#include "Animation.h"
#include "GameTimer.h"

Animation::Animation(int ID, int Total, int StartFrame) : Sprite(ID)
{
	TotalFrame = Total;
	CurrentFrame = StartFrame;
	width = Info.Width / Total;
	SetFrame();
	frame_reset = 1;
	DelayTime = 1.0f / 60;
	RepeatTime = 0;
	delta = 0;
	AnimationTime = 0;
}

Animation::Animation(int name, LPCWSTR Path, D3DXCOLOR TransparentColor, int Total, int StartFrame) : Sprite(Path, TransparentColor)
{
	this->name = name;
	TotalFrame = Total;
	CurrentFrame = StartFrame;
	width = Info.Width / Total;
	SetFrame();
	frame_reset = 1;
	DelayTime = 1.0f / 60;
	RepeatTime = 0;
	delta = 0;
	AnimationTime = 0;
}

void Animation::SetTime(float Delay, float Repeat)
{
	DelayTime = Delay;
	RepeatTime = Repeat;
}

void Animation::Update(float dt)
{
	if (IsStop)
		return;
	delta += dt;
	AnimationTime += dt;
	if (delta >= DelayTime)
	{
		delta -= DelayTime;
		CurrentFrame++;
		if (CurrentFrame == TotalFrame)
			delta -= RepeatTime;
		if (CurrentFrame > TotalFrame)
		{
			CurrentFrame = frame_reset;
			AnimationTime = 0;
			if (!AutoPlayBack)
				IsStop = true;
		}
		SetFrame();
	}
}

void Animation::Pause(float time)
{
	delta -= time;
}

void Animation::Stop()
{
	IsStop = true;
}

void Animation::Continue()
{
	IsStop = false;
}

void Animation::SetFrame(int Frame)
{
	CurrentFrame = Frame;
	delta = 0.0f;
	SetFrame();
}

int Animation::GetNumberCurrentFrame()
{
	return this->CurrentFrame;
}

float Animation::GetAnimationTime()
{
	return this->AnimationTime;
}

void Animation::SetAnimationTime(float time)
{
	this->AnimationTime = time;
}

void Animation::SetFrameReset(int frame)
{
	this->frame_reset = frame;
}

void Animation::ResetAnimation()
{
	delta = 0.0f;
	AnimationTime = 0.0f;
	SetFrame(frame_reset);
}

int Animation::GetName()
{
	return this->name;
}

void Animation::SetAutoPlayBack(bool value)
{
	AutoPlayBack = value;
}

void Animation::SetFrame()
{
	int Right = CurrentFrame * width;
	SetRect(0, Info.Height, Right - width, Right);
}
