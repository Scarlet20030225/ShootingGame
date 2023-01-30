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
		const float mAcceleration = 50.0f;	// �~�T�C���̉����l
		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
};