#pragma once
#include"GameState.h"

#ifndef __OPERATION_METHOD__
#define __OPERATION_METHOD__

namespace App
{
	class OperationMethod:public GameState
	{
	public:
		OperationMethod();
		~OperationMethod();
		GameState* Update(float deltaTime);
		void Draw();
	};
}
#endif // !__OPERATION_METHOD__