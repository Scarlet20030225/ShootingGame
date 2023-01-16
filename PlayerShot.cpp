#include"PlayerShot.h"
#include"Player.h"
#include"AssetManager.h"

using namespace Lib;

namespace App
{
	PlayerShot::PlayerShot(Player* player) : GameObject(ObjectTag::PlayerShot)
	{
		mModelHandle = AssetManager::GetMesh("data/model/Bullet1.mv1");
		MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

		mSpeed = 300.0f;
		mPos = player->GetPos();
		mDir = player->GetDir();

		MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
		MV1SetPosition(mModelHandle, mPos);

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 50.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	PlayerShot::~PlayerShot()
	{
	}

	void PlayerShot::Update(float deltaTime)
	{
		mPos += mDir * deltaTime * mSpeed;
		MV1SetPosition(mModelHandle, mPos);

		mCollisionSphere.Move(mPos);
	}

	void PlayerShot::Draw()
	{
		MV1DrawModel(mModelHandle);

		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 0), 0, FALSE);// å„Ç≈è¡Ç∑
	}
}