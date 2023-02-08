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
		mPos = VGet(1600.0f, 540.0f, 500.0f);	// 初期座標を所得
		mDir = VGet(1.0f, 0.0f, 0.0f);		// 向きを所得

		mModelHandle = AssetManager::GetMesh("data/model/Boss.mv1");		// モデル読み込み	
		MV1SetScale(mModelHandle, VGet(0.6f, 0.6f, 0.6f));		// モデルのスケールを変更
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

		// 弾発射処理
		if (mPos.z == 0)
		{
			mShotTime -= deltaTime;
			if (mShotTime < 0.0f)
			{
				// 発射間隔を設定
				mShotTime = shotInterval;

				// BossShotを呼び出す
				BossShot* bossShot = new App::BossShot(this);
				GameObjectManager::Entry(bossShot);
			}
		}

		mCollisionSphere.Move(mPos);
	}

	void Boss::Draw()
	{
		MV1DrawModel(mModelHandle);	// モデルを描画
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 30, GetColor(255, 0, 0), 0, FALSE);// 後で消す
	}
}