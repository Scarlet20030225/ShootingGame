#include"PlayerShot.h"
#include"Player.h"
#include"AssetManager.h"

using namespace Lib;

namespace App
{
	PlayerShot::PlayerShot(Player* player) : GameObject(ObjectTag::PlayerShot)
		, mRapidModel(-1)
		, mPenetrateModel(-1)
		, mMissileModel(-1)
		, mSpeed(0.0f)
	{
		mRapidModel	    = AssetManager::GetMesh("data/model/Bullet1.mv1");
		mPenetrateModel = AssetManager::GetMesh("data/model/Bullet1.mv1");
		mMissileModel   = AssetManager::GetMesh("data/model/Missile.mv1");

		switch (player->mode)
		{
		case 0:
			mModelHandle = mRapidModel;
			mSpeed = mRapidSpeed;
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.0f, 0.0f, 0.5f, 0.0f));
			MV1SetScale(mModelHandle, VGet(0.03f, 0.03f, 0.03f));
			break;
		case 1:
			mModelHandle = mPenetrateModel;
			mSpeed = mPenetrateSpeed;
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.5f, 0.5f, 0.0f, 0.0f));
			MV1SetScale(mModelHandle, VGet(0.04f, 0.04f, 0.04f));
			break;
		case 2:
			mModelHandle = mMissileModel;
			mSpeed = mMissileSpeed;
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.5f, 0.0f, 0.0f, 0.0f));
			MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));
			break;
		default:
			break;
		}

		mPos = player->GetPos();
		mDir = player->GetDir();

		MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
		MV1SetPosition(mModelHandle, mPos);

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 8.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	PlayerShot::~PlayerShot()
	{
	}

	void PlayerShot::Update(float deltaTime)
	{
		mPos += mDir * deltaTime * mSpeed;

		MV1SetPosition(mModelHandle, mPos);
		MV1SetRotationXYZ(mModelHandle, VGet(0.0f, 0.0f, 0.0f));

		mCollisionSphere.Move(mPos);
	}

	void PlayerShot::Draw()
	{
		MV1DrawModel(mModelHandle);

		//DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(255, 0, 0), 0, FALSE);// å„Ç≈è¡Ç∑
	}
}