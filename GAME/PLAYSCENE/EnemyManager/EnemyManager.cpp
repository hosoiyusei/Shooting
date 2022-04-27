#include"EnemyManager.h"
#include"Enemy/Enemy_0.h"

EnemyManager::EnemyManager()
	:mpEnemy(nullptr)
	, mpBulletManager(nullptr)
	,mpPlayer(nullptr)
{

}

EnemyManager::~EnemyManager()
{

}

void EnemyManager::Initialize(BulletManager* pBulletManager, Player* pPlayer)
{
	mpEnemy = new Enemy_0();
	mpEnemy->Initialize(pBulletManager, pPlayer);

	mpBulletManager = pBulletManager;
	mpPlayer = pPlayer;
}

void EnemyManager::Update()
{
	if (mpEnemy != nullptr)
		mpEnemy->Update();
}

void EnemyManager::Draw()
{
	if (mpEnemy != nullptr)
		mpEnemy->Draw();
}

void EnemyManager::Finalize()
{
	if (mpEnemy != nullptr)
		mpEnemy->Finalize();
	delete mpEnemy;
	mpEnemy = nullptr;
}

void EnemyManager::IsDamage()
{
	mpEnemy->IsDamage();
}

Float2 EnemyManager::GetPos()
{
	return mpEnemy->GetPos();
}

CircleCollider EnemyManager::Collision()
{
	return mpEnemy->Collision();
}