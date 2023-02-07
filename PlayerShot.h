#pragma once
#include"DxLib.h"
#include"math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class PlayerShot : public GameObject
	{
	public:
		PlayerShot(class Player* player);
		~PlayerShot();

		/// <summary>
		/// アップデート処理
		/// </summary>
		/// <param name="deltaTime"></param>
		void Update(float deltaTime);

		/// <summary>
		/// 描画
		/// </summary>
		void Draw();

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		VECTOR mDir;								// 弾の向き
		int mRapidModel;
		int mPenetrateModel;
		int mMissileModel;
		float  mSpeed;								// 弾の速度
		const float mRapidSpeed			 = 1.3f;	// マシンガンの弾の速度
		const float mPenetrateSpeed		 = 1.8f;	// 貫通弾の速度
		const float mMissileAcceleration = 0.1f;	// ミサイルの加速値
		Lib::Sphere mCollisionSphere;				// 当たり判定球
	};
};