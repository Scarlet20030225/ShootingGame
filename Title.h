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
		GameState* Update();
		void Draw();
	};
}
#endif // !__TITLE_H__