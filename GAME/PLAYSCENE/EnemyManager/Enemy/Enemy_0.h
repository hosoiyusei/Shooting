#pragma once
#include"Enemy.h"

class BulletManager;
class Player;

class Enemy_0:public Enemy
{
private:

	Float2 mPos;

	//“–‚½‚è”»’è
	CircleCollider mCollision;

	BulletManager* mpBulletManager;

	Player* mpPlayer;

	int mShotTimer;

	int mShotInterval;

	int mBulletChangeFlag;

	const int mBulletChangeInterval;

	int mBulletChangeTimer;

	int mHpGage, mHpGage2;

	float mHp;

	int mChangeSE;

public:

	Enemy_0();
	~Enemy_0();

	void Initialize(BulletManager* pBulletManager,Player* pPlayer) override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
	Float2 GetPos() override
	{
		return mPos;
	}

	void IsDamage() override;

	CircleCollider Collision() override
	{
		return mCollision;
	}

private:

	void Bullet_1();

	void Bullet_2();

	void Bullet_3();

	void Bullet_4();

	void Bullet_5();

	void Bullet_6();
};