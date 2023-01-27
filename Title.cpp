#include"DxLib.h"
#include"Title.h"
#include"GamePlay.h"

namespace App
{
	Title::Title()
	{
	}

	Title::~Title()
	{
	}

	GameState* Title::Update()
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			return new GamePlay;
		}

		return this;
	}

	void Title::Draw()
	{
	}
}