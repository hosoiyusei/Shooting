#pragma once
#include"../Bullet.h"

class Bullet_0:public Bullet
{
private:

	Float2 mPos;

	//“–‚½‚è”»’è
	CircleCollider mCollision;

	const float mSpeed;

	float mAngle;

	float mX, mY;

	SHOOTER_TYPE mType;

	EnemyManager* mpEnemyManager;

public:

	Bullet_0();
	~Bullet_0();

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

private:

	void ScoreChange() override
	{

	}

	void Player_2();
};