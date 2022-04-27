#pragma once
#include"../../../Utility.h"
#include"../../Collision/Collision.h"
#include"../BulletData.h"

class Player;
class EnemyManager;

class Bullet
{
public:

	virtual ~Bullet() = default;

	virtual void Initialize(Player* pPlayer, EnemyManager* pEnemyManager, float x, float y, SHOOTER_TYPE Shooter) = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Finalize() = 0;

	virtual Float2 GetPos() = 0;

	virtual SHOOTER_TYPE TYPE() = 0;

	virtual CircleCollider Collision() = 0;

	virtual void ScoreChange() = 0;
};