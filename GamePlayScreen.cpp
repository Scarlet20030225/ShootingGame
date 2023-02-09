#include"GamePlayScreen.h"
#include"DxLib.h"

namespace App
{
	GamePlayScreen::GamePlayScreen()
	{
		screenFrame   = LoadGraph("data/graph/ScreenFrame.png");
		lostEndurance = LoadGraph("data/graph/LostEndurance.png");
		lostLife	  = LoadGraph("data/graph/LostLife.png");
		backStar1	  = LoadGraph("data/graph/BackStar1.png");
		backStar2	  = LoadGraph("data/graph/BackStar2.png");
		backStar3	  = LoadGraph("data/graph/BackStar3.png");
	}

	GamePlayScreen::~GamePlayScreen()
	{
	}

	void GamePlayScreen::Init()
	{
		GetGraphSize(backStar1, &backStarW, &backStarH);

		backStar1X[0] =    0;
		backStar1X[1] = 1920;

		backStar2X[0] =	   0;
		backStar2X[1] = 1920;

		backStar3X[0] =	   0;
		backStar3X[1] = 1920;

		backStarY = 0;

		scrollSpeed[0] = 0.5f;
		scrollSpeed[1] = 0.3f;
		scrollSpeed[2] = 0.1f;
	}

	void GamePlayScreen::Update(float deltaTime)
	{
		backStar1X[0] -= scrollSpeed[0] * deltaTime;
		backStar1X[1] -= scrollSpeed[0] * deltaTime;

		backStar2X[0] -= scrollSpeed[1] * deltaTime;
		backStar2X[1] -= scrollSpeed[1] * deltaTime;

		backStar3X[0] -= scrollSpeed[2] * deltaTime;
		backStar3X[1] -= scrollSpeed[2] * deltaTime;
	}

	void GamePlayScreen::Draw()
	{
		DrawGraph(backStar1X[0], backStarY, backStar1, TRUE);
		DrawGraph(backStar1X[1], backStarY, backStar1, TRUE);
		if (backStar1X[0] + backStarW == 0)
		{
			backStar1X[0] = 1920;
		}
		if (backStar1X[1] + backStarW == 0)
		{
			backStar1X[1] = 1920;
		}

		DrawGraph(backStar2X[0], backStarY, backStar2, TRUE);
		DrawGraph(backStar2X[1], backStarY, backStar2, TRUE);
		if (backStar2X[0] + backStarW == 0)
		{
			backStar2X[0] = 1920;
		}
		if (backStar2X[1] + backStarW == 0)
		{
			backStar2X[1] = 1920;
		}

		DrawGraph(backStar3X[0], backStarY, backStar3, TRUE);
		DrawGraph(backStar3X[1], backStarY, backStar3, TRUE);
		if (backStar3X[0] + backStarW == 0)
		{
			backStar3X[0] = 1920;
		}
		if (backStar3X[1] + backStarW == 0)
		{
			backStar3X[1] = 1920;
		}

		DrawGraph(0, 0, screenFrame, TRUE);
	}
}