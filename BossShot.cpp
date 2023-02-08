#include"Boss.h"
#include"BossShot.h"
#include"AssetManager.h"

using namespace Lib;

namespace App
{
	BossShot::BossShot(Boss* boss) : GameObject(ObjectTag::BossShot)
	{
		mModelHandle = AssetManager::GetMesh("data/model/Bullet1.mv1");
		MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));
		MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.5f, 0.0f, 0.0f, 0.0f));

		mSpeed = 1.0f;
		mPos = boss->GetPos();
		mDir = boss->GetDir();

		MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
		MV1SetPosition(mModelHandle, mPos);

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 10.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	BossShot::~BossShot()
	{
	}

	void BossShot::NonExistentArea()
	{
		if (mPos.x < 0 || mPos.x > 1920 || mPos.y < 0 || mPos.y > 1080)	// íeÇ™âÊñ äOÇ…èoÇΩÇÁ
		{
			MV1DeleteModel(mModelHandle);// íeÇè¡ãéÇ∑ÇÈ
		}
	}

	void BossShot::Update(float deltaTime)
	{
		mPos += mDir * deltaTime * -mSpeed;

		MV1SetPosition(mModelHandle, mPos);
		MV1SetRotationXYZ(mModelHandle, VGet(0.0f, 0.0f, 0.0f));

		NonExistentArea();

		mCollisionSphere.Move(mPos);
	}

	void BossShot::Draw()
	{
		MV1DrawModel(mModelHandle);
		//DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(255, 0, 0), 0, FALSE);// å„Ç≈è¡Ç∑
	}
}