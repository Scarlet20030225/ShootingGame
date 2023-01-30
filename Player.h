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
		const float mSpeed			 = 500.0f;	// プレイヤーの速度
		const float mRapidInterval   =   0.2f;	// マシンガンの発射間隔
		const float mHomingInterval  =   0.6f;	// ホーミング弾の発射間隔
		const float mMissileInterval =   1.1f;	// ミサイルの発射間隔
		float mShotTime;
	};
}