#pragma once
#include"DxLib.h"
#include"math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class PlayerShot : public GameObject
	{
	public:
		PlayerShot(class Player* player);
		~PlayerShot();

		void Update(float deltaTime);
		void Draw();

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		VECTOR mDir;
		float  mSpeed;
		Lib::Sphere mCollisionSphere;
	};
};