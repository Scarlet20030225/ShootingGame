#pragma once
#include<DxLib.h>
#include"Math.h"

namespace Lib
{
	struct Sphere
	{
		Sphere();
		Sphere(const VECTOR& center, float radius);
		void Move(const VECTOR& pos);

		VECTOR mLocalCenter;
		VECTOR mWorldCenter;
		float mRadius;
	};

	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2);
}