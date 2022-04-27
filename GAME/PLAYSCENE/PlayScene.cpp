/*
プレイシーン
*/
#include "PlayScene.h"

#include "../GameMain.h"
#include"Player/Player.h"
#include"BulletManager/BulletManager.h"
#include"EnemyManager/EnemyManager.h"
#include"Effect/Effect.h"
#include"../Framework/ResourceManager.h"

/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
PlayScene::PlayScene()
	:mpPlayer(nullptr)
	, mpBulletManager(nullptr)
	, mpEnemyManager(nullptr)
	,mpEffect(nullptr)
	,mBGM(0)
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
PlayScene::~PlayScene()
{
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void PlayScene::Initialize()
{
	mpPlayer = new Player();
	mpBulletManager = new BulletManager();
	mpEnemyManager = new EnemyManager();
	mpEffect = new Effect();

	mpPlayer->Initialize(mpBulletManager, mpEffect);
	mpBulletManager->Initialize(mpPlayer, mpEnemyManager);
	mpEnemyManager->Initialize(mpBulletManager, mpPlayer);
	mpEffect->Initialize();

	ResourceManager* pRm = ResourceManager::GetInstance();
	mBGM = pRm->GetResource("BGM.mp3", TYPE::Audio);
	PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP, TRUE);
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE PlayScene::Update()
{
	

	if (mpBulletManager != nullptr)
		mpBulletManager->Update();
	if (mpEnemyManager != nullptr)
		mpEnemyManager->Update();
	if (mpPlayer != nullptr)
		mpPlayer->Update();
	if (mpEffect != nullptr)
		mpEffect->Update();

	if (IsButtonPressed(PAD_INPUT_2))
	{
		return GAME_SCENE::TITLE;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void PlayScene::Draw()
{
	if (mpPlayer != nullptr)
		mpPlayer->Draw();
	if (mpEnemyManager != nullptr)
		mpEnemyManager->Draw();
	if (mpBulletManager != nullptr)
		mpBulletManager->Draw();
	if (mpEffect != nullptr)
		mpEffect->Draw();

	DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void PlayScene::Finalize()
{
	if (mpPlayer != nullptr)
		mpPlayer->Finalize();
	delete mpPlayer;
	mpPlayer = nullptr;
	if (mpBulletManager != nullptr)
		mpBulletManager->Finalize();
	delete mpBulletManager;
	mpBulletManager = nullptr;
	if (mpEnemyManager != nullptr)
		mpEnemyManager->Finalize();
	delete mpEnemyManager;
	mpEnemyManager = nullptr;
	if (mpEffect != nullptr)
		mpEffect->Finalize();
	delete mpEffect;
	mpEffect = nullptr;
}
