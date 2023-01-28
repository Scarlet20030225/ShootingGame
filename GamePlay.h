#pragma once
#include"GameState.h"

#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

class GameState;

namespace App
{
	class GamePlay : public GameState
	{
	public:
		GamePlay();
		~GamePlay();

		GameState* Update(float deltaTime);
		void Draw();
	};
}
#endif // !__GAMEPLAY_H__