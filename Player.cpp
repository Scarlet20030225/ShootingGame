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
		mPos = VGet(100.0f, 540.0f, 0.0f);	// 初期座標を所得
		mDir = VGet(1.0f, 0.0f, 0.0f);		// 向きを所得

		mModelHandle = AssetManager::GetMesh("data/model/Player.mv1");	// モデル読み込み
		MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));		// モデルのスケールを変更

		mode = 0;

		mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
		mCollisionSphere.mRadius = 50.0f;
		mCollisionSphere.mWorldCenter = mPos;
	}

	Player::~Player()
	{
	}

	void Player::Update(float deltaTime)
	{
		VECTOR inputVec = VGet(0, 0, 0);

		// 移動キーの入力があるか？
		bool input = false;

		// 上移動
		VECTOR UP = { 0,  1,  0 };
		if (CheckHitKey(KEY_INPUT_UP))
		{
			inputVec += UP;
			input = true;
		}

		// 下移動
		VECTOR DOWN = { 0, -1,  0 };
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			inputVec += DOWN;
			input = true;
		}

		// 右移動
		VECTOR RIGHT = { 1,  0,  0 };
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			inputVec += RIGHT;
			input = true;
		}

		// 下移動
		VECTOR LEFT = { -1,  0,  0 };
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			inputVec += LEFT;
			input = true;
		}

		// 上下or左右の同時入力を確認すると入力をしなかったことにする
		if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)
			|| CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_DOWN))
		{
			input = false;
		}

		if (input)
		{
			// 斜め移動時の移動量を調整
			if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP)
				|| CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN)
				|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP)
				|| CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN))
			{
				float normalization = 0.71;	// √2を割る
				mPos = mPos + inputVec * deltaTime * mSpeed * normalization;	// 正規化
			}

			// 通常時の移動量
			else
			{
				mPos = mPos + inputVec * deltaTime * mSpeed;
			}

			mCollisionSphere.Move(mPos);
		}

		if (CheckHitKey(KEY_INPUT_Z))
		{
			mode = 0;
		}

		if (CheckHitKey(KEY_INPUT_X))
		{
			mode = 1;
		}

		if (CheckHitKey(KEY_INPUT_C))
		{
			mode = 2;
		}

		if (mode == 0)
		{
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(0.0f, 0.0f, 1.0f, 0.0f));
		}

		if (mode == 1)
		{
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(1.0f, 1.0f, 0.0f, 0.0f));
		}

		if (mode == 2)
		{
			MV1SetMaterialEmiColor(mModelHandle, 0, GetColorF(1.0f, 0.0f, 0.0f, 0.0f));
		}

		// 弾発射処理
		mShotTime -= deltaTime;
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			if (mShotTime < 0.0f)
			{
				// 発射間隔を設定
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

				// PlayerShotを呼び出す
				PlayerShot* pb = new App::PlayerShot(this);
				GameObjectManager::Entry(pb);
			}
		}

		MV1SetPosition(mModelHandle, mPos);

		if (input)
		{
			// 上移動時に機体をX軸-30°傾ける
			if (CheckHitKey(KEY_INPUT_UP)
				|| (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP))
				|| (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP)))
			{
				MV1SetRotationXYZ(mModelHandle, VGet(60.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			}

			// 下移動時に機体をX軸+30°傾ける
			if (CheckHitKey(KEY_INPUT_DOWN)
				|| (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN))
				|| (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN)))
			{
				MV1SetRotationXYZ(mModelHandle, VGet(120.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			}
		}

		// 上下移動していない際の機体(傾きなし)
		else
		{
			MV1SetRotationXYZ(mModelHandle, VGet(90.0f * DX_PI_F / 180.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
		}
	}

	void Player::Draw()
	{
		MV1DrawModel(mModelHandle);	// モデルを描画
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(255, 0, 0), 0, FALSE);// 後で消す
	}
}