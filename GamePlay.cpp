#include"DxLib.h"
#include"GamePlay.h"
#include"Title.h"
#include"Result.h"

namespace App
{
	GamePlay::GamePlay()
	{
	}

	GamePlay::~GamePlay()
	{
	}

	GameState* GamePlay::Update(float deltaTime)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			return new Title;
		}


		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			return new Result;
		}
		return this;
	}

	void GamePlay::Draw()
	{
	}
}