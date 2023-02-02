#pragma once
#include"DxLib.h"
#include"math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class BossShot : public GameObject
	{
	public:
		BossShot();
		~BossShot();

		/// <summary>
		/// �A�b�v�f�[�g����
		/// </summary>
		/// <param name="deltaTime"></param>
		void Update(float deltaTime);

		/// <summary>
		/// �`��
		/// </summary>
		void Draw();

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		VECTOR mDir;						// �e�̌���
		float  mMissileSpeed;				// �~�T�C���̑��x
		const float mAcceleration = 0.1f;	// �~�T�C���̉����l
		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
}