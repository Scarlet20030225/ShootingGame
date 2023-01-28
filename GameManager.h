#pragma once
#include"DxLib.h"

namespace App
{
	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void GameInit();
		void GameLoop();
		void GameEndProcessing();
	};
}