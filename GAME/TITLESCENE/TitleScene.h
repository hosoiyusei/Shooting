/*
�^�C�g���V�[��
*/
#pragma once

#include "../IScene.h"

class TitleScene : public IScene
{
private:

	int mTest;

public:

	// �R���X�g���N�^
	TitleScene();

	// �f�X�g���N�^
	~TitleScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;
};