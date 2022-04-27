#include"Bullet_1.h"
#include<math.h>
#include"../../../Player/Player.h"

Bullet_1::Bullet_1(float x, float y)
	:mPos()
	, mCollision()
	, mSpeed(3.0f)
	,mAngle(0.0f)
	,mTimer(0)
	,mX(x)
	,mY(y)
	,mX2(0.0f)
	,mY2(0.0f)
	,mpPlayer(nullptr)
{

}

Bullet_1::~Bullet_1()
{

}

void Bullet_1::Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter)
{
	mPos.mX = x;
	mPos.mY = y;

	//ìñÇΩÇËîªíËÇÃèâä˙âª
	mCollision.mRadius = 5;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	mType = Shooter;

	mpPlayer = pPlayer;
}

void Bullet_1::Update()
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
	
	mPos.mX += mX2;
	mPos.mY += mY2;

	//íeÇÃìñÇΩÇËîªíË
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Bullet_1::Draw()
{
	if (mType == SHOOTER_TYPE::TYPE_ENEMY)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 0, 255), TRUE);
	if (mType == SHOOTER_TYPE::TYPE_SCORE)
		DrawCircle(mPos.mX, mPos.mY, 5, GetColor(255, 255, 255), FALSE);
}

void Bullet_1::Finalize()
{

}

void Bullet_1::Shot()
{
	mAngle = atan2f(mY - mPos.mY, mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_1::Score()
{
	if (mSpeed < 10.0f)
		mSpeed += 0.1f;

	mAngle = atan2f(mpPlayer->GetPos().mY - mPos.mY, mpPlayer->GetPos().mX - mPos.mX);

	mX2 = mSpeed * cos(mAngle);
	mY2 = mSpeed * sin(mAngle);
}

void Bullet_1::ScoreChange()
{
	mType = SHOOTER_TYPE::TYPE_SCORE;
	mSpeed = 0.0f;
}