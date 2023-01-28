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
		VECTOR mDir;						// ’e‚ÌŒü‚«
		float  mSpeed;						// ’e‚Ì‘¬“x
		const float mAcceleration = 50.0f;	// ’e‚Ì‰Á‘¬’l
		Lib::Sphere mCollisionSphere;		// “–‚½‚è”»’è‹…
	};
};