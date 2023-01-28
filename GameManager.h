#pragma once
#include"DxLib.h"
#include"Player.h"
#include"GameState.h"

namespace App
{
	class GameManager
	{
	public:
		GameManager();		// コンストラクタ
		~GameManager();		// デストラクタ

		void Init();		// 初期化
		void Loop();		// ループ
		void Finalize();	// 後処理

	private:
		LONGLONG nowCount, prevCount;
		float fixedDeltaTime = 1.0f / 60.0f;
		float waitFrameTime = 15500;

		LARGE_INTEGER* freq;
		LARGE_INTEGER* start;
		LARGE_INTEGER* end;

		Player* player;
		GameState* gameState;
	};
}