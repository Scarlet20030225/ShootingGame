#pragma once
#include"DxLib.h"
#include"GameState.h"
#include"CollisionDetection.h"
#include"Camera.h"
#include"GamePlayScreen.h"

namespace App
{
	class GameManager
	{
	public:
		GameManager();		// コンストラクタ
		~GameManager();		// デストラクタ

		/// <summary>
		/// ループ
		/// </summary>
		void Loop();

		/// <summary>
		/// 後処理
		/// </summary>
		void Finalize();

	private:
		Player*     player;
		PlayerShot* playerShot;
		Boss*       boss;
		BossShot*   bossShot;
		GameState*  gameState;
		Camera*     camera;
		CollisionDetection* collisionDetection;
		GamePlayScreen* gamePlaySceen;

		// ウィンドウ関連
		int screenSizeX   = 1920;	// スクリーン幅
		int screenSizeY   = 1080;	// スクリーン高さ
		int colorBitDepth =   32;	// カラービット数

		// フレーム関連
		int fps;
		int deltaTime;
	};
}