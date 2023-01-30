#pragma once
#include"DxLib.h"
#include"Math.h"
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

	private:
		const float mSpeed		  = 500.0f;	// プレイヤーの速度
		const float mShotInterval = 1.03f;	// 弾の発射間隔
		float mShotTime;
	};
}