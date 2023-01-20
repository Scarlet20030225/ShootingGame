#pragma once
#include"DxLib.h"
#include"Math.h"
#include"GameObject.h"

namespace App
{
	class Player :public GameObject
	{
	public:
		Player();
		~Player();

		void Update(float deltaTime) override;
		void Draw() override;

	private:
		const float mSpeed = 500.0f;
		const float mShotInterval = 1.0f;
		float mShotTime;
	};
}