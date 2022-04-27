#pragma once
#include"../../../Utility.h"
#include"../../../GameMain.h"
#include"../../Collision/Collision.h"
#include"../../BulletManager/BulletManager.h"
#include"../../Player/Player.h"


class Enemy
{
public:

	virtual ~Enemy() = default;
	virtual void Initialize(BulletManager* pBulletManager, Player* pPlayer) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;
	virtual Float2 GetPos() = 0;
	virtual void IsDamage() = 0;
	virtual CircleCollider Collision() = 0;
};