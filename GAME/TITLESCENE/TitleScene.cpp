/*
�^�C�g���V�[��
*/
#include "TitleScene.h"

#include "../GameMain.h"
#include"../Framework/ResourceManager.h"

/*--------------------------------------------------
�R���X�g���N�^
--------------------------------------------------*/
TitleScene::TitleScene()
	:mTest(0)
{
}

/*--------------------------------------------------
�f�X�g���N�^
--------------------------------------------------*/
TitleScene::~TitleScene()
{
}

/*--------------------------------------------------
������
--------------------------------------------------*/
void TitleScene::Initialize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();

	mTest = pRm->GetResource("TridentLogo.png", TYPE::Textures);
}

/*--------------------------------------------------
�X�V
�߂�l	:���̃V�[���ԍ�
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
�`��
--------------------------------------------------*/
void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));

	DrawRectRotaGraph(
		SCREEN_CENTER_X,//X�̈ʒu
		SCREEN_CENTER_Y,//Y�̈ʒu
		0,//�؂���J�n�̈ʒu
		0,//�؂���J�n�̈ʒu
		2500,//�؂���I���̈ʒu
		1500,//�؂���I���̈ʒu
		0.655,//�g��
		0.0,//��]
		mTest,//�A�h���X
		TRUE
	);
}

/*--------------------------------------------------
�I������
--------------------------------------------------*/
void TitleScene::Finalize()
{
	ResourceManager* pRm = ResourceManager::GetInstance();
	pRm->DeleteResource();
}
