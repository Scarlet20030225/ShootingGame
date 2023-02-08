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
		int mRapidModel;							// マシンガンモデル
		int mPenetrateModel;						// 貫通弾モデル
		int mMissileModel;							// ミサイルモデル
		float  mSpeed;								// 弾の速度
		const float mRapidSpeed			 = 2.0f;	// マシンガンの弾の速度
		const float mPenetrateSpeed		 = 2.5f;	// 貫通弾の速度
		const float mMissileSpeed		 = 1.5f;	// ミサイルの速度

		Lib::Sphere mCollisionSphere;				// 当たり判定球
	};
};