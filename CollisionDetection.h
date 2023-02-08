#pragma once
#include"Player.h"
#include"PlayerShot.h"
#include"Boss.h"
#include"BossShot.h"
#include"Collision.h"

namespace App
{
	class CollisionDetection
	{
	public:
		CollisionDetection();
		~CollisionDetection();
		
		void Detection();

	private:
		Player* player;
		PlayerShot* playerShot;
		Boss* boss;
		BossShot* bossShot;
	};
}