#pragma once
#include<DxLib.h>

namespace Lib
{
	VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

	VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

	VECTOR operator*(float s, const VECTOR& rhs);

	VECTOR operator*(const VECTOR& lhs, float s);

	VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

	VECTOR operator*=(VECTOR& lhs, float rhs);

	bool IsNearAngle(const VECTOR& v1, const VECTOR& v2);

	float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec);

	VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVerocity);
}