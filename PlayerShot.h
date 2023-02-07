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
		VECTOR mDir;								// �e�̌���
		int mRapidModel;
		int mPenetrateModel;
		int mMissileModel;
		float  mSpeed;								// �e�̑��x
		const float mRapidSpeed			 = 1.3f;	// �}�V���K���̒e�̑��x
		const float mPenetrateSpeed		 = 1.8f;	// �ђʒe�̑��x
		const float mMissileAcceleration = 0.1f;	// �~�T�C���̉����l
		Lib::Sphere mCollisionSphere;				// �����蔻�苅
	};
};