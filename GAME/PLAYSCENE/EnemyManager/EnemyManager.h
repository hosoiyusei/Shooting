#pragma once
#include"../Collision/Collision.h"
#include"../../Utility.h"

class Enemy;
class BulletManager;
class Player;

class EnemyManager
{
private:

	Enemy* mpEnemy;

	BulletManager* mpBulletManager;

	Player* mpPlayer;

public:

	EnemyManager();
	~EnemyManager();

	void Initialize(BulletManager* pBulletManager, Player* pPlayer);

	void Update();

	void Draw();

	void Finalize();

	void IsDamage();

	Float2 GetPos();

	CircleCollider Collision();
};