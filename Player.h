#pragma once
#include"DxLib.h"
#include"Math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class Player :public GameObject
	{
	public:
		Player();
		~Player();

		/// <summary>
		/// アップデート処理
		/// </summary>
		/// <param name="deltaTime"></param>
		void Update(float deltaTime) override;

		/// <summary>
		/// 描画処理
		/// </summary>
		void Draw() override;

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		const float mSpeed			 =   1.0f;	// プレイヤーの速度
		const float mRapidInterval   = 200.0f;	// マシンガンの発射間隔
		const float mHomingInterval  = 450.0f;	// ホーミング弾の発射間隔
		const float mMissileInterval = 600.0f;	// ミサイルの発射間隔
		float mShotTime;

		Lib::Sphere mCollisionSphere;		// 当たり判定球
	};
}