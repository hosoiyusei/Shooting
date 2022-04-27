#include"Bullet_3.h"
#include<math.h>
#include"../../../Player/Player.h"

Bullet_3::Bullet_3(float x, float y)
	:mPos()
	, mCollision()
	, mSpeed(1.5f)
	, mAngle(0.0f)
	, mTimer(0)
	, mX(x)
	, mY(y)
	, mX2(0.0f)
	, mY2(0.0f)
	, mpPlayer(nullptr)
	, mSearchTimer(0)
{

}

Bullet_3::~Bullet_3()
{

}

void Bullet_3::Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter)
{
	mPos.mX = x;
	mPos.mY = y;

	//“–‚½‚è”»’è‚Ì‰Šú‰»
	mCollision.mRadius = 10;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	mType = Shooter;

	mpPlayer = pPlayer;
}

void Bullet_3::Update()
{
	if (mTimer == 0)
	{
		Shot();
		++mTimer;
	}

	if (mType == SHOOTER_TYPE::TYPE_SCORE)
	{
		Score();
	}

	if (mSearchTimer != 201)
		mSearchTimer++;

	if (mSearchTimer == 100 || mSearchTimer == 200)
		Shot2();

	mPos.mX += mX2;
	mPos.mY += mY2;

	//’e‚Ì“–‚½‚è”»’è
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Bullet_3::Draw()
{
	if (mType == SHOOTER_TYPE::TYPE_ENEMY)
		DrawCircle(mPos.mX, mPos.mY, 10, GetColor(255, 0, 255), TRUE);
	if (mType == SHOOTER_TYPE::TYPE_SCORE)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 255, 255), FALSE);
}

void Bullet_3::Finalize()
{

}

void Bullet_3::Shot()
{
	mAngle = atan2f(mY - mPos.mY, mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_3::Shot2()
{
	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_3::Score()
{
	if (mSpeed < 10.0f)
		mSpeed += 0.1f;

	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_3::ScoreChange()
{
	mType = SHOOTER_TYPE::TYPE_SCORE;
	mSpeed = 0.0f;
}