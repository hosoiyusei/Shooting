#pragma once
#include"../../Utility.h"
#include"../Collision/Collision.h"
#include"../BulletManager/BulletData.h"

class BulletManager;
class Effect;

class Player
{
private:

	Float2 mPos;

	//“–‚½‚è”»’è
	CircleCollider mCollision;

	const float mSpeed;

	int mShotTimer;

	const int mShotInterval;

	const int mPlayerSize;

	int mScore;

	int mBulletTypeFlag;

	bool mActiveFlag;

	int mActiveInterval;
	int mActiveTimer;

	bool mResetPos;

	int mMouseX;
	int mMouseY;

	BulletManager* mpBulletManager;

	Effect* mpEffect;

public:

	Player();
	~Player();

	void Initialize(BulletManager* pBulletManager, Effect* pEffect);

	void Update();

	void Draw();

	void Finalize();

	Float2 GetPos()
	{
		return mPos;
	}

	void IsDamage();

	void IsScore();

	CircleCollider Collision()
	{
		return mCollision;
	}

	bool Active()
	{
		return mActiveFlag;
	}

private:

	void Move();

	void ResetPos();
};