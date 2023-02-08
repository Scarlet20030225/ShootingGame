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
		BossShot(class Boss* boss);
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
		/// <summary>
		/// ���݂ł��Ȃ��̈�
		/// </summary>
		void NonExistentArea();

		VECTOR mDir;						// �e�̌���
		float  mSpeed;						// �e�̑��x
		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
}