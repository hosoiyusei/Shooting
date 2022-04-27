#include"Bullet_0.h"
#include<math.h>
#include"../../../EnemyManager/EnemyManager.h"

Bullet_0::Bullet_0()
	:mPos()
	, mCollision()
	, mSpeed(10.0f)
	,mX(0.0f)
	,mY(0.0f)
	,mAngle(0.0f)
	,mpEnemyManager(nullptr)
{

}

Bullet_0::~Bullet_0()
{

}

void Bullet_0::Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter)
{
	mPos.mX = x;
	mPos.mY = y;

	//“–‚½‚è”»’è‚Ì‰Šú‰»
	mCollision.mRadius = 5;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	mType = Shooter;

	mpEnemyManager = pEnemyManager;
}

void Bullet_0::Update()
{
	if (mType == SHOOTER_TYPE::TYPE_PLAYER)
		mPos.mY -= mSpeed;
	if (mType == SHOOTER_TYPE::TYPE_PLAYER2)
		Player_2();

	//’e‚Ì“–‚½‚è”»’è
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Bullet_0::Draw()
{
	if (mType == SHOOTER_TYPE::TYPE_PLAYER)
		DrawCircle(mPos.mX, mPos.mY, 3, GetColor(0, 255, 255), TRUE);
	if (mType == SHOOTER_TYPE::TYPE_PLAYER2)
		DrawCircle(mPos.mX, mPos.mY, 3, GetColor(255, 255, 255), TRUE);
}

void Bullet_0::Finalize()
{

}

void Bullet_0::Player_2()
{
	mAngle = atan2f(mpEnemyManager->GetPos().mY - mPos.mY, mpEnemyManager->GetPos().mX - mPos.mX);

	mX = mSpeed * cos(mAngle);
	mY = mSpeed * sin(mAngle);

	mPos.mX += mX;
	mPos.mY += mY;
}