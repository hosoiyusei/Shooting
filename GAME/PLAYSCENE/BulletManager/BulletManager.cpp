#include"BulletManager.h"
#include"../Player/Player.h"
#include"../EnemyManager/EnemyManager.h"
#include"../../GameMain.h"
#include <random>

#include"Bullet/Bullet_0/Bullet_0.h"
#include"Bullet/Bullet_1/Bullet_1.h"
#include"Bullet/Bullet_2/Bullet_2.h"
#include"Bullet/Bullet_3/Bullet_3.h"
#include"Bullet/Bullet_4/Bullet_4.h"

BulletManager::BulletManager()
	:mpBullet()
	,itr()
	,mpPlayer(nullptr)
	,mpEnemyManager(nullptr)
{

}

BulletManager::~BulletManager()
{

}

void BulletManager::Initialize(Player* pPlayer, EnemyManager* pEnemyManager)
{
	mpPlayer = pPlayer;
	mpEnemyManager = pEnemyManager;
}

void BulletManager::Update()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Update();
	}

	BulletDelete();
	BulletDelete();
	BulletDelete();
	
	HitPlayer();
	
	HitEnemy();
}

void BulletManager::Draw()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Draw();
	}

	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", mpBullet.size());
}

void BulletManager::Finalize()
{
	int S = mpBullet.size();
	for (int i = 0; i < S; i++)
	{
		for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
		{
			if ((*itr) == nullptr)
				continue;
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpBullet.erase(itr);
			break;
		}
	}
}

//Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°

void BulletManager::Shot(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	if (num == BULLET_NUM::BULLET_0)
	{
		mpBullet.push_back(new Bullet_0());
		itr = mpBullet.end();
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
	else if (num == BULLET_NUM::BULLET_1)
	{
		Bullet1_1a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_2)
	{
		Bullet1_2a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_3)
	{
		Bullet1_3a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_4)
	{
		Bullet1_4a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_5)
	{
		Bullet1_5b(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_6)
	{
		Bullet2_1a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_7)
	{
		Bullet3_1a(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_8)
	{
		Bullet1_6c(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_9)
	{
		Bullet2_1b(x, y, Shooter, num);
	}
	else if (num == BULLET_NUM::BULLET_10)
	{
		Bullet4_1a(x, y, Shooter, num);
	}
}

void BulletManager::BulletDelete()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) == nullptr)
			continue;
		if ((*itr)->GetPos().mY < -300|| (*itr)->GetPos().mY > SCREEN_BOTTOM+100|| (*itr)->GetPos().mX<-100|| (*itr)->GetPos().mX>SCREEN_RIGHT+100)
		{
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpBullet.erase(itr);
			break;
		}
	}
}

void BulletManager::ChangeScore()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) == nullptr)
			continue;
		if ((*itr)->TYPE() == SHOOTER_TYPE::TYPE_PLAYER)
			continue;

		(*itr)->ScoreChange();
	}
}

void BulletManager::HitEnemy()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) == nullptr ||
			(*itr)->TYPE() == SHOOTER_TYPE::TYPE_ENEMY||
			(*itr)->TYPE() == SHOOTER_TYPE::TYPE_SCORE)
			continue;
		if ((*itr)->Collision().CheckHit(mpEnemyManager->Collision()) == false)
			continue;

		mpEnemyManager->IsDamage();

		(*itr)->Finalize();
		delete (*itr);
		(*itr) = nullptr;
		mpBullet.erase(itr);
		break;
	}
}

void BulletManager::HitPlayer()
{
	for (itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
	{
		if ((*itr) == nullptr ||
			(*itr)->TYPE() == SHOOTER_TYPE::TYPE_PLAYER ||
			(*itr)->TYPE() == SHOOTER_TYPE::TYPE_PLAYER2)
			continue;
		if ((*itr)->Collision().CheckHit(mpPlayer->Collision()) == false)
			continue;
		if ((*itr)->TYPE() == SHOOTER_TYPE::TYPE_SCORE)
		{
			mpPlayer->IsScore();
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpBullet.erase(itr);
			break;
		}
		else if ((*itr)->TYPE() == SHOOTER_TYPE::TYPE_ENEMY && mpPlayer->Active() == true)
		{
			mpPlayer->IsDamage();
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpBullet.erase(itr);
			break;
		}
	}
}

//Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°

void BulletManager::Bullet1_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	mpBullet.push_back(new Bullet_1(SCREEN_RIGHT,									50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(SCREEN_RIGHT - SCREEN_CENTER_X / 2,				50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X / 2,							50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X,								50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(SCREEN_LEFT,									50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(SCREEN_RIGHT,									50+SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(SCREEN_LEFT,									50+SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(SCREEN_RIGHT,									50+y));
	mpBullet.push_back(new Bullet_1(SCREEN_LEFT,									50+y));
	mpBullet.push_back(new Bullet_1(SCREEN_RIGHT,									50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_LEFT,									50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X / 2,							50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X + SCREEN_CENTER_X / 2,			50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X,								50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X - (SCREEN_CENTER_X / 4),		50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X + (SCREEN_CENTER_X / 4),		50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X - (SCREEN_CENTER_X / 8),		50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(SCREEN_CENTER_X + (SCREEN_CENTER_X / 8),		50+SCREEN_TOP));
	itr = mpBullet.end();
	for (int i = 0; i < 18; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet1_2a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	mpBullet.push_back(new Bullet_1(100+SCREEN_RIGHT,								50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(100+SCREEN_RIGHT - SCREEN_CENTER_X / 2,			50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X / 2,						50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X,							50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(100+SCREEN_LEFT,								50+SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(100+SCREEN_RIGHT,								50+SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(100+SCREEN_LEFT,								50+SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(100+SCREEN_RIGHT,								50+y));
	mpBullet.push_back(new Bullet_1(100+SCREEN_LEFT,								50+y));
	mpBullet.push_back(new Bullet_1(100+SCREEN_RIGHT,								50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_LEFT,								50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X / 2,						50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X + SCREEN_CENTER_X / 2,		50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X,							50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X - (SCREEN_CENTER_X / 4),	50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X + (SCREEN_CENTER_X / 4),	50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X - (SCREEN_CENTER_X / 8),	50+SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(100+SCREEN_CENTER_X + (SCREEN_CENTER_X / 8),	50+SCREEN_TOP));
	itr = mpBullet.end();
	for (int i = 0; i < 18; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet1_3a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	mpBullet.push_back(new Bullet_1(50 + SCREEN_RIGHT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_RIGHT - SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_LEFT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_RIGHT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_LEFT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_RIGHT, y));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_LEFT, y));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_RIGHT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_LEFT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X + SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X - (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X + (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X - (SCREEN_CENTER_X / 8), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(50 + SCREEN_CENTER_X + (SCREEN_CENTER_X / 8), SCREEN_TOP));
	itr = mpBullet.end();
	for (int i = 0; i < 18; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet1_4a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	mpBullet.push_back(new Bullet_1(150 +SCREEN_RIGHT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_RIGHT - SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_LEFT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_RIGHT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_LEFT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_RIGHT, y));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_LEFT, y));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_RIGHT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_LEFT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X + SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X, SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X - (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X + (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X - (SCREEN_CENTER_X / 8), SCREEN_TOP));
	mpBullet.push_back(new Bullet_1(150 +SCREEN_CENTER_X + (SCREEN_CENTER_X / 8), SCREEN_TOP));
	itr = mpBullet.end();
	for (int i = 0; i < 18; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet1_5b(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<int> distX(0, SCREEN_RIGHT);
	std::uniform_int_distribution<int> distY(0, SCREEN_BOTTOM);
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	itr = mpBullet.end();
	for (int i = 0; i < 5; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet1_6c(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<int> distX(0, SCREEN_RIGHT);
	std::uniform_int_distribution<int> distY(0, SCREEN_BOTTOM);
	mpBullet.push_back(new Bullet_1(distX(mt), distY(mt)));
	itr = mpBullet.end();
	(--itr);
	(*itr)->Initialize(mpPlayer, mpEnemyManager, distX(mt), SCREEN_TOP, Shooter);
}

void BulletManager::Bullet2_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	mpBullet.push_back(new Bullet_2(SCREEN_RIGHT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_2(SCREEN_RIGHT - SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X / 2, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_2(SCREEN_LEFT, SCREEN_BOTTOM));
	mpBullet.push_back(new Bullet_2(SCREEN_RIGHT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_2(SCREEN_LEFT, SCREEN_CENTER_Y));
	mpBullet.push_back(new Bullet_2(SCREEN_RIGHT, y));
	mpBullet.push_back(new Bullet_2(SCREEN_LEFT, y));
	mpBullet.push_back(new Bullet_2(SCREEN_RIGHT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_LEFT, SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X + SCREEN_CENTER_X / 2, SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X, SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X - (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X + (SCREEN_CENTER_X / 4), SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X - (SCREEN_CENTER_X / 8), SCREEN_TOP));
	mpBullet.push_back(new Bullet_2(SCREEN_CENTER_X + (SCREEN_CENTER_X / 8), SCREEN_TOP));
	itr = mpBullet.end();
	for (int i = 0; i < 18; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet2_1b(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<int> distX(0, SCREEN_RIGHT);
	std::uniform_int_distribution<int> distY(0, SCREEN_BOTTOM);
	mpBullet.push_back(new Bullet_2(distX(mt), distY(mt)));
	itr = mpBullet.end();
	(--itr);
	(*itr)->Initialize(mpPlayer, mpEnemyManager, distX(mt), SCREEN_TOP, Shooter);
}

void BulletManager::Bullet3_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<int> distX(0, SCREEN_RIGHT);
	std::uniform_int_distribution<int> distY(0, SCREEN_BOTTOM);
	mpBullet.push_back(new Bullet_3(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_3(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_3(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_3(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_3(distX(mt), distY(mt)));
	itr = mpBullet.end();
	for (int i = 0; i < 5; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}

void BulletManager::Bullet4_1a(float x, float y, SHOOTER_TYPE Shooter, BULLET_NUM num)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<int> distX(0, SCREEN_RIGHT);
	std::uniform_int_distribution<int> distY(-100, SCREEN_BOTTOM-200);
	mpBullet.push_back(new Bullet_4(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_4(distX(mt), distY(mt)));
	mpBullet.push_back(new Bullet_4(distX(mt), distY(mt)));
	itr = mpBullet.end();
	for (int i = 0; i < 5; i++)
	{
		(--itr);
		(*itr)->Initialize(mpPlayer, mpEnemyManager, x, y, Shooter);
	}
}