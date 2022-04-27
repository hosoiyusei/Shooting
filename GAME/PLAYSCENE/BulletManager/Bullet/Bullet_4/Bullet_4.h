#pragma once
#include"../Bullet.h"

class Player;

class Bullet_4 :public Bullet
{
private:

	Float2 mPos;

	//“–‚½‚è”»’è
	CircleCollider mCollision;

	float mSpeed;

	float mAngle;

	float mX, mY, mX2, mY2;

	int mTimer;

	SHOOTER_TYPE mType;

	Player* mpPlayer;

public:

	Bullet_4(float x, float y);
	~Bullet_4();

	void Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter) override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

	Float2 GetPos() override
	{
		return mPos;
	}

	SHOOTER_TYPE TYPE() override
	{
		return mType;
	}

	CircleCollider Collision() override
	{
		return mCollision;
	}

	void ScoreChange() override;

private:

	void Shot();

	void Score();
};