#pragma once
#include"GameState.h"

#ifndef __TITLE_H__
#define __TITLE_H__

class GameState;

namespace App
{
	class Title : public GameState
	{
	public:
		Title();
		~Title();
		GameState* Update(float deltaTime);
		void Draw();

	private:
		int mGraph;
	};
}
#endif // !__TITLE_H__