#pragma once
#include"GameState.h"

#ifndef __RESULT_H__
#define __RESULT_H__

class GameState;

namespace App
{
	class Result : public GameState
	{
	public:
		Result();
		~Result();

		GameState* Update();
		void Draw();
	};
}
#endif // !__RESULT_H__