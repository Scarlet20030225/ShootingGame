#include"Boss.h"
#include"BossShot.h"
#include"AssetManager.h"
#include"GameObjectManager.h"

using namespace Lib;

namespace App
{
	Boss::Boss() : GameObject(ObjectTag::Boss)
		, mShotTime(0.0f)
	{
		mPos = VGet(1600.0f, 540.0f, 500.0f);	// �������W������
		mDir = VGet(1.0f, 0.0f, 0.0f);		// ����������

		mModelHandle = AssetManager::GetMesh("data/model/Boss.mv1");		// ���f���ǂݍ���	
		MV1SetScale(mModelHandle, VGet(0.6f, 0.6f, 0.6f));		// ���f���̃X�P�[����ύX
		MV1SetRotationXYZ(mModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f));

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 300.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	Boss::~Boss()
	{
	}

	void Boss::Update(float deltaTime)
	{
		MV1SetPosition(mModelHandle, mPos);

		if (mPos.z > 0)
		{
			mPos.z -= 2;
		}

		// �e���ˏ���
		if (mPos.z == 0)
		{
			mShotTime -= deltaTime;
			if (mShotTime < 0.0f)
			{
				// ���ˊԊu��ݒ�
				mShotTime = shotInterval;

				// BossShot���Ăяo��
				BossShot* bossShot = new App::BossShot(this);
				GameObjectManager::Entry(bossShot);
			}
		}

		mCollisionSphere.Move(mPos);
	}

	void Boss::Draw()
	{
		MV1DrawModel(mModelHandle);	// ���f����`��
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 30, GetColor(255, 0, 0), 0, FALSE);// ��ŏ���
	}
}