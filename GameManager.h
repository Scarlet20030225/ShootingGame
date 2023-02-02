#pragma once
#include"DxLib.h"
#include"Player.h"
#include"Boss.h"
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
		Boss* boss;
		GameState* gameState;
		Camera* camera;

		// ウィンドウ関連
		int screenSizeX   = 1920;	// スクリーン幅
		int screenSizeY   = 1080;	// スクリーン高さ
		int colorBitDepth =   32;	// カラービット数

		// フレーム関連
		int fps;
		int deltaTime;
	};
}