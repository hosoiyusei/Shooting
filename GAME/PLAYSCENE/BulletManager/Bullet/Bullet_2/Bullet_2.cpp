#include"Bullet_2.h"
#include<math.h>
#include"../../../Player/Player.h"

Bullet_2::Bullet_2(float x, float y)
	:mPos()
	, mCollision()
	, mSpeed(3.0f)
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

Bullet_2::~Bullet_2()
{

}

void Bullet_2::Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter)
{
	mPos.mX = x;
	mPos.mY = y;

	//“–‚½‚è”»’è‚Ì‰Šú‰»
	mCollision.mRadius = 5;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	mType = Shooter;

	mpPlayer = pPlayer;
}

void Bullet_2::Update()
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

	if (mSearchTimer != 51)
		mSearchTimer++;

	if (mSearchTimer == 50)
		Shot2();

	mPos.mX += mX2;
	mPos.mY += mY2;

	//’e‚Ì“–‚½‚è”»’è
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Bullet_2::Draw()
{
	if (mType == SHOOTER_TYPE::TYPE_ENEMY)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 0, 255), TRUE);
	if (mType == SHOOTER_TYPE::TYPE_SCORE)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 255, 255), FALSE);
}

void Bullet_2::Finalize()
{

}

void Bullet_2::Shot()
{
	mAngle = atan2f(mY - mPos.mY, mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_2::Shot2()
{
	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_2::Score()
{
	if (mSpeed < 10.0f)
		mSpeed += 0.1f;

	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_2::ScoreChange()
{
	mType = SHOOTER_TYPE::TYPE_SCORE;
	mSpeed = 0.0f;
}