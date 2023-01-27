#include"PlayerShot.h"
#include"Player.h"
#include"AssetManager.h"

using namespace Lib;

namespace App
{
	PlayerShot::PlayerShot(Player* player) : GameObject(ObjectTag::PlayerShot)
	{
		mModelHandle = AssetManager::GetMesh("data/model/Missile.mv1");
		MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));

		mSpeed = 0.0f;
		mPos = player->GetPos();
		mDir = player->GetDir();

		MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
		MV1SetPosition(mModelHandle, mPos);

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 10.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	PlayerShot::~PlayerShot()
	{
	}

	void PlayerShot::Update(float deltaTime)
	{
		mSpeed += mAcceleration;
		mPos += mDir * deltaTime * mSpeed;
		MV1SetPosition(mModelHandle, mPos);
		MV1SetRotationXYZ(mModelHandle, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));

		mCollisionSphere.Move(mPos);
	}

	void PlayerShot::Draw()
	{
		MV1DrawModel(mModelHandle);

		//DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(255, 0, 0), 0, FALSE);// å„Ç≈è¡Ç∑
	}
}