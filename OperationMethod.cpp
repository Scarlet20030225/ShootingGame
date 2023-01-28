#include"Title.h"
#include"OperationMethod.h"
#include"DxLib.h"

namespace App
{
	OperationMethod::OperationMethod()
	{
	}

	OperationMethod::~OperationMethod()
	{
	}

	GameState* OperationMethod::Update(float deltaTime)
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			return new Title;
		}

		return this;
	}

	void OperationMethod::Draw()
	{
	}
}