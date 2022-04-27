#pragma once
#include"../../Utility.h"

enum class EFFECT_NUM :int
{
	EFFECT_1,
	EFFECT_2,
	EFFECT_3,

	EFFECT_START,
};

class Effect
{
private:

	Float2 mPos[3];

	int mEffectResourceHandle;
	int mEffectResourceHandle2;
	int mEffectResourceHandle3;
	int mEffectResourceHandle4;

	int mEffect1;
	int mEffect2;
	int mEffect3;

	int mTimer;

	int mStartTimer;

public:

	Effect();
	~Effect();

	void Initialize();

	void Update();

	void Draw();

	void Finalize();

	void Play(float x, float y, EFFECT_NUM num);
};