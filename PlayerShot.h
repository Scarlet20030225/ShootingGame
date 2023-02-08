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
		int mRapidModel;							// �}�V���K�����f��
		int mPenetrateModel;						// �ђʒe���f��
		int mMissileModel;							// �~�T�C�����f��
		float  mSpeed;								// �e�̑��x
		const float mRapidSpeed			 = 2.0f;	// �}�V���K���̒e�̑��x
		const float mPenetrateSpeed		 = 2.5f;	// �ђʒe�̑��x
		const float mMissileSpeed		 = 1.5f;	// �~�T�C���̑��x

		Lib::Sphere mCollisionSphere;				// �����蔻�苅
	};
};