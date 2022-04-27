/*
タイトルシーン
*/
#include "TitleScene.h"

#include "../GameMain.h"
#include"../Framework/ResourceManager.h"

/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
TitleScene::TitleScene()
	:mTest(0)
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
TitleScene::~TitleScene()
{
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void TitleScene::Initialize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();

	mTest = pRm->GetResource("TridentLogo.png", TYPE::Textures);
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE TitleScene::Update()
{
	if (IsButtonPressed(PAD_INPUT_1))
	{
		return GAME_SCENE::PLAY;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));

	DrawRectRotaGraph(
		SCREEN_CENTER_X,//Xの位置
		SCREEN_CENTER_Y,//Yの位置
		0,//切り取り開始の位置
		0,//切り取り開始の位置
		2500,//切り取り終わりの位置
		1500,//切り取り終わりの位置
		0.655,//拡大
		0.0,//回転
		mTest,//アドレス
		TRUE
	);
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void TitleScene::Finalize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();
	pRm->DeleteResource();
}
