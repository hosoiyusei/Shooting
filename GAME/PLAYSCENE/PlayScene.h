/*
プレイシーン
*/
#pragma once

#include "../IScene.h"


class Player;
class BulletManager;
class EnemyManager;
class Effect;

class PlayScene : public IScene
{
private:

	Player* mpPlayer;

	BulletManager* mpBulletManager;

	EnemyManager* mpEnemyManager;

	Effect* mpEffect;

	int mBGM;

public:

	// コンストラクタ
	PlayScene();

	// デストラクタ
	~PlayScene();

	// 初期化
	void Initialize() override;

	// 更新
	GAME_SCENE Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;
};