#pragma once
#include <list>
#include"BulletData.h"

class Bullet;
class Player;
class EnemyManager;

class BulletManager
{
private:

	std::list<Bullet*> mpBullet;
	std::list<Bullet*>::iterator itr;

	Player* mpPlayer;

	EnemyManager* mpEnemyManager;

public:

	BulletManager();
	~BulletManager();

	void Initialize(Player* pPlayer, EnemyManager* pEnemyManager);

	void Update();

	void Draw();

	void Finalize();

	void Shot(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void ChangeScore();

private:

	void BulletDelete();

	void HitPlayer();

	void HitEnemy();

	void Bullet1_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet1_2a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet1_3a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet1_4a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet1_5b(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet1_6c(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet2_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet2_1b(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet3_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);

	void Bullet4_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num);
};