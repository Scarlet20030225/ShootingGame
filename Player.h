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
		const float mShotInterval = 0.03f;
		const float mSpeed = 500.0f;
		float mShotTime;
	};
}