/*
�v���C�V�[��
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

	// �R���X�g���N�^
	PlayScene();

	// �f�X�g���N�^
	~PlayScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;
};