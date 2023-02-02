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
		mPos = VGet(1600.0f, 540.0f, 0.0f);	// 初期座標を所得
		mDir = VGet(1.0f, 0.0f, 0.0f);		// 向きを所得

		mModelHandle = AssetManager::GetMesh("data/model/Boss.mv1");		// モデル読み込み	
		MV1SetScale(mModelHandle, VGet(0.6f, 0.6f, 0.6f));		// モデルのスケールを変更
		MV1SetRotationXYZ(mModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f));
	}

	Boss::~Boss()
	{
	}

	void Boss::Update(float deltaTime)
	{
		MV1SetPosition(mModelHandle, mPos);

	}

	void Boss::Draw()
	{
		MV1DrawModel(mModelHandle);	// モデルを描画
	}
}