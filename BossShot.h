#pragma once
#include"DxLib.h"
#include"math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class BossShot : public GameObject
	{
	public:
		BossShot(class Boss* boss);
		~BossShot();

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
		VECTOR mDir;						// 弾の向き
		float  mSpeed;						// 弾の速度
		Lib::Sphere mCollisionSphere;		// 当たり判定球
	};
}