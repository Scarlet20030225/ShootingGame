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
		mPos = VGet(100.0f, 540.0f, 0.0f);
		mDir = VGet(1.0f, 0.0f, 0.0f);

		mModelHandle = AssetManager::GetMesh("data/model/Player.mv1");
		MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));
	}

	Player::~Player()
	{
	}

	void Player::Update(float deltaTime)
	{
		VECTOR UP = { 0, 1, 0 };
		VECTOR DOWN = { 0, -1, 0 };
		VECTOR LEFT = { -1, 0, 0 };
		VECTOR RIGHT = { 1, 0, 0 };

		VECTOR inputVec = VGet(0, 0, 0);
		bool input = false;

		if (CheckHitKey(KEY_INPUT_UP))
		{
			inputVec += UP;
			input = true;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			inputVec += DOWN;
			input = true;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			inputVec += RIGHT;
			input = true;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			inputVec += LEFT;
			input = true;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_DOWN))
		{
			input = false;
		}
		if (input)
		{
			VNorm(inputVec);
			mPos = mPos + inputVec * deltaTime * mSpeed;
		}

		mShotTime -= deltaTime;

		if (mShotTime < 0.0f && CheckHitKey(KEY_INPUT_SPACE))
		{
			mShotTime = mShotInterval;
			PlayerShot* pb = new App::PlayerShot(this);
			GameObjectManager::Entry(pb);
		}

		MV1SetPosition(mModelHandle, mPos);

		MV1SetRotationXYZ(mModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));

		//MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
		//VECTOR negativeVec = VTransform(mDir, rotYMat);

		//MV1SetRotationZYAxis(mModelHandle, negativeVec, VGet(0.0f, 1.0f, 0.0f), 1.0f);
	}

	void Player::Draw()
	{
		MV1DrawModel(mModelHandle);
	}
}