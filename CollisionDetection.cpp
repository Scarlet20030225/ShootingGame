#include "CollisionDetection.h"
#pragma warning(disable:4996)

using namespace Lib;

namespace App
{
	CollisionDetection::CollisionDetection()
	{
		player = new App::Player();
		playerShot = new App::PlayerShot(player);
		boss = new App::Boss();
		bossShot = new App::BossShot(boss);
	}

	CollisionDetection::~CollisionDetection()
	{
	}

	void CollisionDetection::Detection()
	{
		if (playerShot != nullptr && boss != nullptr)
		{
			Lib::Sphere spherePlayerShot, sphereBoss;

			spherePlayerShot = playerShot->GetCollsionSphere();
			sphereBoss		 = boss->GetCollsionSphere();

			printfDx("spherePlayerShot.xÅF%f", spherePlayerShot.mWorldCenter.x);
			if (Lib::CollisionPair(spherePlayerShot, sphereBoss))
			{
				DrawString(100, 100, "HIT", GetColor(255, 0, 0));
			}
		}
	}
}