#pragma once
#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

namespace App
{
	class GameState
	{
	public:
		GameState();
		virtual ~GameState() {};

		virtual		 GameState* Update(float deltaTime) = 0;
		virtual void Draw() = 0;

	protected:
		VECTOR mPos;
		int mGraphHandle;
	};
}
#endif // !__GAMESTATE_H__