#pragma once

namespace App
{
	class GamePlayScreen
	{
	public:
		GamePlayScreen();
		~GamePlayScreen();

		void Update(float deltaTime);
		void Draw();

	private:
		int screenFrameGraph;
		int lostEnduranceGraph;
		int lostLifeGraph;

		int backStar1Graph;
		int backStar1X[2];

		int backStar2Graph;
		int backStar2X[2];

		int backStar3Graph;
		int backStar3X[2];

		int backStarY;
		int backStarW;
		int backStarH;

		float scrollSpeed[3];
	};
}