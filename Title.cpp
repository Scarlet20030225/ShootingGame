#include"DxLib.h"
#include"Title.h"
#include"GamePlay.h"
#include"OperationMethod.h"

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
		if (CheckHitKey(KEY_INPUT_Z))
		{
			return new OperationMethod;
		}

		return this;
	}

	void Title::Draw()
	{
	}
}