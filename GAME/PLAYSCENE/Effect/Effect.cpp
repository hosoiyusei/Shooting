#include"Effect.h"
#include "EffekseerForDXLib.h"
#include"../../Framework/ResourceManager.h"

Effect::Effect()
	:mEffectResourceHandle(0)
	, mEffectResourceHandle2(0)
	, mEffectResourceHandle3(0)
	, mEffectResourceHandle4(0)
	,mEffect1(0)
	, mEffect2(0)
	, mEffect3(0)
	,mTimer(0)
	,mPos()
	,mStartTimer(0)
{

}

Effect::~Effect()
{

}

void Effect::Initialize()
{
	// Zバッファを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	SetUseZBuffer3D(TRUE);

	// Zバッファへの書き込みを有効にする。
	// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
	SetWriteZBuffer3D(TRUE);

	ResourceManager* pRm = ResourceManager::GetInstance();

	mEffectResourceHandle = pRm->GetResource("laser.efk", TYPE::Effect, 20);
	mEffectResourceHandle2 = pRm->GetResource("Breakdown.efk", TYPE::Effect, 20);
	mEffectResourceHandle3 = pRm->GetResource("Gohlem1.efk", TYPE::Effect, 20);
	mEffectResourceHandle4 = pRm->GetResource("Test.efk", TYPE::Effect, 20);

	//mEffect1 = PlayEffekseer2DEffect(mEffectResourceHandle);
}

void Effect::Update()
{
	if (mStartTimer < 2)
		mStartTimer++;
	if (mStartTimer == 1)
		Play(-200, -200, EFFECT_NUM::EFFECT_START);

	SetPosPlayingEffekseer2DEffect(mEffect1, mPos[0].mX, mPos[0].mY, 0);
	SetPosPlayingEffekseer2DEffect(mEffect2, mPos[1].mX, mPos[1].mY, 0);
	SetPosPlayingEffekseer2DEffect(mEffect3, mPos[2].mX, mPos[2].mY, 0);

	UpdateEffekseer2D();
}

void Effect::Draw()
{
	DrawEffekseer2D();
}

void Effect::Finalize()
{
	//DeleteEffekseerEffect(mEffectResourceHandle);
}

void Effect::Play(float x, float y, EFFECT_NUM num)
{
	if (num == EFFECT_NUM::EFFECT_1)
	{
		mEffect1 = PlayEffekseer2DEffect(mEffectResourceHandle);
		mPos[0].mX = x;
		mPos[0].mY = y;
	}
	else if (num == EFFECT_NUM::EFFECT_2)
	{
		mEffect2 = PlayEffekseer2DEffect(mEffectResourceHandle2);
		mPos[1].mX = x;
		mPos[1].mY = y;
	}
	else if (num == EFFECT_NUM::EFFECT_3)
	{
		mEffect3 = PlayEffekseer2DEffect(mEffectResourceHandle3);
		mPos[2].mX = x;
		mPos[2].mY = y;
	}
	else if (num == EFFECT_NUM::EFFECT_START)
	{
		mEffect3 = PlayEffekseer2DEffect(mEffectResourceHandle4);
		mPos[2].mX = x;
		mPos[2].mY = y;
	}
}