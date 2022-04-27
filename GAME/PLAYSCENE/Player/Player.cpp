#include"Player.h"
#include<corecrt_math.h>
#include"../../GameMain.h"
#include"../BulletManager/BulletManager.h"
#include"../Effect/Effect.h"

Player::Player()
	:mPos()
	, mSpeed(5.0f)
	, mCollision()
	, mpBulletManager(nullptr)
	,mpEffect(nullptr)
	, mShotTimer(0)
	, mShotInterval(5)
	, mPlayerSize(2)
	,mScore(0)
	, mBulletTypeFlag(0)
	,mActiveFlag(false)
	, mActiveInterval(180)
	, mActiveTimer(0)
	, mResetPos(true)
	,mMouseX(0)
	,mMouseY(0)
{

}

Player::~Player()
{

}

void Player::Initialize(BulletManager* pBulletManager, Effect* pEffect)
{
	mPos.mX = SCREEN_CENTER_X;
	mPos.mY = SCREEN_BOTTOM + 50;

	//�����蔻��̏�����
	mCollision.mRadius = mPlayerSize;
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;

	mpBulletManager = pBulletManager;
	mpEffect = pEffect;
}

void Player::Update()
{
	GetMousePoint(&mMouseX, &mMouseY);

	

	++mShotTimer %= mShotInterval;
	if (mShotTimer == 0)
	{
		if (mBulletTypeFlag == 0)
		{
			mpBulletManager->Shot(mPos.mX - 10, mPos.mY + 5, SHOOTER_TYPE::TYPE_PLAYER2, BULLET_NUM::BULLET_0);
			mpBulletManager->Shot(mPos.mX + 10, mPos.mY + 5, SHOOTER_TYPE::TYPE_PLAYER2, BULLET_NUM::BULLET_0);
			mpBulletManager->Shot(mPos.mX, mPos.mY, SHOOTER_TYPE::TYPE_PLAYER, BULLET_NUM::BULLET_0);
		}
		else if (mBulletTypeFlag == 1)
		{
			mpBulletManager->Shot(mPos.mX - 10, mPos.mY + 5, SHOOTER_TYPE::TYPE_PLAYER, BULLET_NUM::BULLET_0);
			mpBulletManager->Shot(mPos.mX + 10, mPos.mY + 5, SHOOTER_TYPE::TYPE_PLAYER, BULLET_NUM::BULLET_0);
			mpBulletManager->Shot(mPos.mX, mPos.mY, SHOOTER_TYPE::TYPE_PLAYER, BULLET_NUM::BULLET_0);
		}
	}
		
	if (IsButtonPressed(PAD_INPUT_5) == TRUE)
	{
		if (mBulletTypeFlag == 0)
		{
			mBulletTypeFlag = 1;
		}
		else
		{
			mBulletTypeFlag = 0;
		}
	}

	ResetPos();

	//�����蔻��ɍ��W�𔽉f
	mCollision.mPos.mX = mPos.mX;
	mCollision.mPos.mY = mPos.mY;
}

void Player::Draw()
{
	DrawCircle(mPos.mX, mPos.mY, mPlayerSize, GetColor(255, 255, 255), TRUE);
	DrawCircle(mPos.mX, mPos.mY, 10, GetColor(255, 255, 255), FALSE);

	DrawFormatString(0, 120, GetColor(255, 255, 255), "%d", mScore);
}

void Player::Finalize()
{
	
}

void Player::Move()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 &&
		mMouseX<SCREEN_RIGHT && mMouseX>SCREEN_LEFT &&
		mMouseY<SCREEN_BOTTOM && mMouseY>SCREEN_TOP &&
		mPos.mX + 50 > mMouseX && mPos.mX - 50 < mMouseX &&
		mPos.mY + 50 > mMouseY && mPos.mY - 50 < mMouseY)
	{

		mPos.mX = mMouseX;
		mPos.mY = mMouseY;
	}

	//�ړ�
	int inputUD = 0;
	int inputLR = 0;

	//�㉺
	if (IsButtonDown(PAD_INPUT_UP) == TRUE)
	{
		inputUD = -1;
	}

	if (IsButtonDown(PAD_INPUT_DOWN) == TRUE)
	{
		inputUD = 1;
	}

	//���E
	if (IsButtonDown(PAD_INPUT_LEFT) == TRUE)
	{
		inputLR = -1;
	}

	if (IsButtonDown(PAD_INPUT_RIGHT) == TRUE)
	{
		inputLR = 1;
	}

	//���͂���Ă��Ȃ��Ȃ炱��ȏ㏈�����Ȃ�
	if (inputUD == 0 && inputLR == 0)
	{
		return;
	}

	//���͏����x�N�g���v�Z�p��float�^�֕ϊ�
	float vx = (float)inputLR;
	float vy = (float)inputUD;

	//�x�N�g���̒������擾
	float vl = sqrtf((vx * vx) + (vy * vy));

	//�P�ʃx�N�g��(������1�̃x�N�g��)���v�Z
	vx /= vl;
	vy /= vl;

	//�ړ��x�N�g����ړI�̑傫��(�ړ���)�ɃX�P�[�����O
	vx *= mSpeed;
	vy *= mSpeed;

	//�ړ��ʂ����W�ɉ��Z
	mPos.mX += vx;
	mPos.mY += vy;

	//���W�̈ړ�����
	mPos.mX = ClampF(mPos.mX, SCREEN_LEFT, SCREEN_RIGHT);
	mPos.mY = ClampF(mPos.mY, SCREEN_TOP, SCREEN_BOTTOM);
}

void Player::IsDamage()
{
	if (mActiveFlag == true)
	{
		if (mpEffect != nullptr)
			mpEffect->Play(mPos.mX, mPos.mY, EFFECT_NUM::EFFECT_1);
		mActiveFlag = false;
		mActiveTimer = 0;

		mPos.mX = SCREEN_CENTER_X;
		mPos.mY = SCREEN_BOTTOM + 50;
		mResetPos = true;
	}
}

void Player::IsScore()
{
	++mScore;
}

void Player::ResetPos()
{
	if (mPos.mY > SCREEN_BOTTOM - 50&& mResetPos==true)
	{
		mPos.mY--;
	}
	else
	{
		mResetPos = false;
		Move();
	}

	if (mActiveFlag == false)
		mActiveTimer++;

	if (mActiveTimer > mActiveInterval)
		mActiveFlag = true;
}