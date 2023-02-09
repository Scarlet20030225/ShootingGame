#pragma once

namespace App
{
	class GamePlayScreen
	{
	public:
		GamePlayScreen();
		~GamePlayScreen();

		void Init();
		void Update(float deltaTime);
		void Draw();

	private:
		int screenFrame;
		int lostEndurance;
		int lostLife;

		int backStar1;
		int backStar1X[2];

		int backStar2;
		int backStar2X[2];

		int backStar3;
		int backStar3X[2];

		int backStarY;
		int backStarW;
		int backStarH;

		float scrollSpeed[3];
	};
}