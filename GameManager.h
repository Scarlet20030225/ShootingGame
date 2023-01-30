#pragma once
#include"DxLib.h"
#include"Player.h"
#include"GameState.h"
#include"Camera.h"

namespace App
{
	class GameManager
	{
	public:
		GameManager();		// コンストラクタ
		~GameManager();		// デストラクタ

		/// <summary>
		/// 初期化
		/// </summary>
		void Init();

		/// <summary>
		/// ループ
		/// </summary>
		void Loop();

		/// <summary>
		/// 後処理
		/// </summary>
		void Finalize();

	private:
		LONGLONG nowCount, prevCount;
		float fixedDeltaTime = 1.0f / 60.0f;
		float waitFrameTime = 15500;

		LARGE_INTEGER* freq;
		LARGE_INTEGER* start;
		LARGE_INTEGER* end;

		Player* player;
		GameState* gameState;
		Camera* camera;
	};
}