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
		mDir = VGet(0.0f, 0.0f, 1.0f);

		mModelHandle = AssetManager::GetMesh("data/model/Type1.mv1");
	}

	Player::~Player()
	{
	}

	void Player::Update(float deltaTime)
	{
		VECTOR UP = { 0, 0, 1 };
		VECTOR DOWN = { 0, 0,-1 };
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
		if (input)
		{
			inputVec = VNorm(inputVec);

			mDir = inputVec;

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

		MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
		VECTOR negativeVec = VTransform(mDir, rotYMat);

		MV1SetRotationZYAxis(mModelHandle, negativeVec, VGet(0.0f, 1.0f, 0.0f), 0.0f);
	}

	void Player::Draw()
	{
		MV1DrawModel(mModelHandle);
	}
}