#include"Enemy_0.h"
#include"../../../Framework/ResourceManager.h"

Enemy_0::Enemy_0()
	:mPos()
	, mCollision()
	, mpBulletManager(nullptr)
	,mpPlayer(nullptr)
	,mShotInterval(100)
	,mShotTimer(0)
	, mBulletChangeFlag(0)
	, mBulletChangeInterval(100)
	, mBulletChangeTimer(0)
	,mHpGage(0)
	,mHpGage2(0)
	, mHp(0.0f)
	,mChangeSE(0)
{

}

Enemy_0::~Enemy_0()
{

}

void Enemy_0::Initialize(BulletManager* pBulletManager, Player* pPlayer)
{
	mPos.mX = SCREEN_CENTER_X;
	mPos.mY = 100;

	//“–‚½‚è”»’è‚Ì‰Šú‰»
	mCollision.mRadius = 20;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	ResourceManager* pRm = ResourceManager::GetInstance();
	mHpGage = pRm->GetResource("EnemyHp.png", TYPE::Textures);
	mHpGage2 = pRm->GetResource("EnemyHp2.png", TYPE::Textures);
	mChangeSE= pRm->GetResource("Change.mp3", TYPE::Audio);

	mpBulletManager = pBulletManager;
	mpPlayer = pPlayer;
}

void Enemy_0::Update()
{
	if (mBulletChangeFlag == 0)
	{
		if(mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 100;
			Bullet_1();
		}
	}
	else if (mBulletChangeFlag == 1)
	{
		if (mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 10;
			Bullet_2();
		}
	}
	else if (mBulletChangeFlag == 2)
	{
		if (mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 50;
			Bullet_3();
		}
	}
	else if (mBulletChangeFlag == 3)
	{
		if (mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 50;
			Bullet_4();
		}
	}
	else if (mBulletChangeFlag == 4)
	{
		if (mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 2;
			Bullet_5();
		}
	}
	else if (mBulletChangeFlag == 5)
	{
		if (mBulletChangeTimer == 0)
			mpBulletManager->ChangeScore();
		if (mBulletChangeTimer != mBulletChangeInterval)
		{
			++mBulletChangeTimer;
		}
		else if (mBulletChangeTimer == mBulletChangeInterval)
		{
			mShotInterval = 5;
			Bullet_6();
		}
	}
	
	++mShotTimer %= mShotInterval;

	if (IsButtonPressed(PAD_INPUT_3) == TRUE)
	{
		mBulletChangeTimer = 0;
		if (mBulletChangeFlag != 5)
		{
			mBulletChangeFlag += 1;
		}
		else if (mBulletChangeFlag == 5)
			mBulletChangeFlag = 0;
	}

	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Enemy_0::Draw()
{
	DrawCircle(mPos.mX, mPos.mY, 20, GetColor(255, 255, 0), TRUE);

	DrawCircleGauge(mPos.mX, mPos.mY, 100, mHpGage2,mHp,1);//˜g
	DrawCircleGauge(mPos.mX, mPos.mY, 100, mHpGage, 0);//ƒQ[ƒW
}

void Enemy_0::Finalize()
{

}

void Enemy_0::IsDamage()
{
	mHp += 0.5f;
	if (mHp >= 100.0f)
	{
		PlaySoundMem(mChangeSE, DX_PLAYTYPE_BACK, TRUE);
		mHp = 0;
		mBulletChangeTimer = 0;
		if (mBulletChangeFlag == 5)
		{
			mBulletChangeFlag = 0;
		}
		else if (mBulletChangeFlag != 5)
		{
			mBulletChangeFlag += 1;
		}
	}
		
}

void Enemy_0::Bullet_1()
{
	if (mShotTimer == 0)
	{
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_1);
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_6);
	}

	if (mShotTimer == 10)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_3);

	if (mShotTimer == 20)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_2);

	if (mShotTimer == 30)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_4);
}

void Enemy_0::Bullet_2()
{
	if (mShotTimer == 0)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_5);
}

void Enemy_0::Bullet_3()
{
	if (mShotTimer == 0)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_6);
}

void Enemy_0::Bullet_4()
{
	if (mShotTimer == 0)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_7);
}

void Enemy_0::Bullet_5()
{
	if (mShotTimer == 0)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_8);
}

void Enemy_0::Bullet_6()
{
	if (mShotTimer == 0)
		mpBulletManager->Shot(mPos.mX, mPos.mY,
			SHOOTER_TYPE::TYPE_ENEMY,
			BULLET_NUM::BULLET_9);
}