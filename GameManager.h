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
		Player* player;
		GameState* gameState;
		Camera* camera;

		int fps;
		int deltaTime;
	};
}