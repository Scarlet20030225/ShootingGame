#include "Math.h"

namespace Lib
{
	VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = lhs.x + rhs.x;
		ret.y = lhs.y + rhs.y;
		ret.z = lhs.z + rhs.z;
		return ret;
	}

	VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = lhs.x - rhs.x;
		ret.y = lhs.y - rhs.y;
		ret.z = lhs.z - rhs.z;
		return ret;
	}

	VECTOR operator*(float s, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = s * rhs.x;
		ret.y = s * rhs.y;
		ret.z = s * rhs.z;
		return ret;
	}

	VECTOR operator*(const VECTOR& lhs, float s)
	{
		VECTOR ret;
		ret.x = s * lhs.x;
		ret.y = s * lhs.y;
		ret.z = s * lhs.z;
		return ret;
	}

	VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
	{
		lhs = lhs + rhs;
		return lhs;
	}

	VECTOR operator*=(VECTOR& lhs, float rhs)
	{
		lhs = lhs * rhs;
		return lhs;
	}

	bool IsNearAngle(const VECTOR& v1, const VECTOR& v2)
	{
		float dot = VDot(v1, v2);
		if (dot > 0.99f)
		{
			return true;
		}
		return false;
	}

	float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec)
	{
		VECTOR axis;
		axis = VCross(nowVec, dirVec);
		if (axis.y < 0.0f)
		{
			return -1.0f;
		}
		return 1.0f;
	}

	VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVerocity)
	{
		float rotRadian = (DX_PI_F * degreeVerocity / 180.0f);
		rotRadian *= CalcRotationDirectionYAxis(nowVec, aimVec);

		MATRIX yrotMat = MGetRotY(rotRadian);

		VECTOR rotVec;
		rotVec = VTransform(nowVec, yrotMat);

		return rotVec;
	}
}