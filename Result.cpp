#include"DxLib.h"
#include"Result.h"
#include"Title.h"

namespace App
{
	Result::Result()
	{
	}

	Result::~Result()
	{
	}

	GameState* Result::Update(float deltaTime)
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			return new Title;
		}

		return this;
	}

	void Result::Draw()
	{
	}
}