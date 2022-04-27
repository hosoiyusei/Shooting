#include"Bullet_4.h"
#include<math.h>
#include"../../../Player/Player.h"

Bullet_4::Bullet_4(float x, float y)
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
{

}

Bullet_4::~Bullet_4()
{

}

void Bullet_4::Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter)
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

void Bullet_4::Update()
{
	if (mSpeed > -3.0f && mType != SHOOTER_TYPE::TYPE_SCORE)
	{
		if (mSpeed < 0)
		{
			mSpeed -= 0.1f;
		}
		else
			mSpeed -= 0.02f;
	}
		
	
	Shot();
	//++mTimer;
	

	if (mType == SHOOTER_TYPE::TYPE_SCORE)
	{
		Score();
	}

	mPos.mX += mX2;
	mPos.mY += mY2;

	//’e‚Ì“–‚½‚è”»’è
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Bullet_4::Draw()
{
	if (mType == SHOOTER_TYPE::TYPE_ENEMY)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 0, 255), TRUE);
	if (mType == SHOOTER_TYPE::TYPE_SCORE)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 255, 255), FALSE);
}

void Bullet_4::Finalize()
{

}

void Bullet_4::Shot()
{
	mAngle = atan2f(mY - mPos.mY, mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_4::Score()
{
	if (mSpeed < 10.0f)
		mSpeed += 0.1f;

	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_4::ScoreChange()
{
	mType = SHOOTER_TYPE::TYPE_SCORE;
	mSpeed = 0.0f;
}