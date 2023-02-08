#include"Player.h"
#include"PlayerShot.h"
#include"AssetManager.h"
#include"GameObjectManager.h"

using namespace Lib;

namespace App
{
	Player::Player() : GameObject(ObjectTag::Player)
		, mShotTime(0.0f)
	{
		mPos = VGet(100.0f, 540.0f, 0.0f);	// �������W������
		mDir = VGet(1.0f, 0.0f, 0.0f);		// ����������

		mModelHandle = AssetManager::GetMesh("data/model/Player.mv1");	// ���f���ǂݍ���
		MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));		// ���f���̃X�P�[����ύX

		mode = 0;	// ���[�h���}�V���K�����[�h��

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 50.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	Player::~Player()
	{
	}

	void Player::MovableRange()
	{
		if (mPos.x <= 50)
		{
			mPos.x = 50;
		}
		if (mPos.x >= 1700)
		{
			mPos.x = 1700;
		}
		if (mPos.y <= 100)
		{
			mPos.y = 100;
		}
		if (mPos.y >= 980)
		{
			mPos.y = 980;
		}
	}

	void Player::ModeChange()
	{
		if (CheckHitKey(KEY_INPUT_Z))
		{
			mode = 0;	// ���[�h���}�V���K�����[�h��
		}
		if (CheckHitKey(KEY_INPUT_X))
		{
			mode = 1;	// ���[�h���ђʒe���[�h��
		}
		if (CheckHitKey(KEY_INPUT_C))
		{
			mode = 2;	// ���[�h���~�T�C�����[�h��
		}

		// ���[�h���Ƃɋ@�̂̐F��ύX
		switch (mode)
		{
		case 0:
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 0.0f));		// �F��F��
			break;
		case 1:
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(1.0f, 1.0f, 0.0f, 0.0f));		// �F�����F��
			break;
		case 2:
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(1.0f, 0.0f, 0.0f, 0.0f));		// �F��ԐF��
			break;
		default:
			break;
		}
	}

	void Player::Update(float deltaTime)
	{
		VECTOR inputVec = VGet(0, 0, 0);

		bool input = false;	// �ړ��L�[�̓��͂����邩�H

		// ��ړ�
		VECTOR UP = { 0, 1, 0 };
		if (CheckHitKey(KEY_INPUT_UP))
		{
			inputVec += UP;
			input = true;
		}
		// ���ړ�
		VECTOR DOWN = { 0, -1, 0 };
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			inputVec += DOWN;
			input = true;
		}
		// �E�ړ�
		VECTOR RIGHT = { 1, 0, 0 };
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			inputVec += RIGHT;
			input = true;
		}
		// ���ړ�
		VECTOR LEFT = { -1, 0, 0 };
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			inputVec += LEFT;
			input = true;
		}
		// �㉺or���E�̓������͂��m�F����Ɠ��͂����Ȃ��������Ƃɂ���
		if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)
			|| CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_DOWN))
		{
			input = false;
		}
		if (input)
		{
			// �΂߈ړ����̈ړ��ʂ𒲐�
			if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP)
				|| CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN)
				|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP)
				|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN))
			{
				float normalization = 0.71;	// ��2������
				mPos = mPos + inputVec * deltaTime * mSpeed * normalization;	// ���K��
			}
			// �ʏ펞�̈ړ���
			else
			{
				mPos = mPos + inputVec * deltaTime * mSpeed;
			}

			mCollisionSphere.Move(mPos);
		}

		MV1SetPosition(mModelHandle, mPos);

		if (input)
		{
			// ��ړ����ɋ@�̂�X��-30���X����
			if (CheckHitKey(KEY_INPUT_UP)
				|| (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP))
				|| (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP)))
			{
				MV1SetRotationXYZ(mModelHandle, VGet(60.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			}

			// ���ړ����ɋ@�̂�X��+30���X����
			if (CheckHitKey(KEY_INPUT_DOWN)
				|| (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN))
				|| (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN)))
			{
				MV1SetRotationXYZ(mModelHandle, VGet(120.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			}
		}
		// �㉺�ړ����Ă��Ȃ��ۂ̋@��(�X���Ȃ�)
		else
		{
			MV1SetRotationXYZ(mModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
		}

		MovableRange();
		ModeChange();

		// �e���ˏ���
		mShotTime -= deltaTime;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			if (mShotTime < 0.0f)
			{
				// ���ˊԊu��ݒ�
				switch (mode)
				{
				case 0:
					mShotTime = mRapidInterval;
					break;
				case 1:
					mShotTime = mPenetrateInterval;
					break;
				case 2:
					mShotTime = mMissileInterval;
					break;
				default:
					break;
				}

				// PlayerShot���Ăяo��
				PlayerShot* pb = new App::PlayerShot(this);
				GameObjectManager::Entry(pb);
			}
		}
	}

	void Player::Draw()
	{
		MV1DrawModel(mModelHandle);	// ���f����`��
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(255, 0, 0), 0, FALSE);// ��ŏ���
	}
}