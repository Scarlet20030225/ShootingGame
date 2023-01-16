#include "Collision.h"

namespace Lib
{
	Sphere::Sphere()
		: mLocalCenter()
		, mWorldCenter()
		, mRadius(0.0f)
	{
	}

	Sphere::Sphere(const VECTOR& center, float radius)
		: mLocalCenter(center)
		, mWorldCenter(center)
		, mRadius(radius)
	{
	}

	void Sphere::Move(const VECTOR& pos)
	{
		mWorldCenter = mLocalCenter + pos;
	}

	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2)
	{
		return HitCheck_Sphere_Sphere(sphere1.mWorldCenter, sphere1.mRadius, sphere2.mWorldCenter, sphere2.mRadius);
	}
}