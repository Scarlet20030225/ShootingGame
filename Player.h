#pragma once
#include"DxLib.h"
#include"Math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class Player :public GameObject
	{
	public:
		Player();
		~Player();

		/// <summary>
		/// �A�b�v�f�[�g����
		/// </summary>
		/// <param name="deltaTime"></param>
		void Update(float deltaTime) override;

		/// <summary>
		/// �`�揈��
		/// </summary>
		void Draw() override;

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		const float mSpeed			 =   1.0f;	// �v���C���[�̑��x
		const float mRapidInterval   = 200.0f;	// �}�V���K���̔��ˊԊu
		const float mHomingInterval  = 450.0f;	// �z�[�~���O�e�̔��ˊԊu
		const float mMissileInterval = 600.0f;	// �~�T�C���̔��ˊԊu
		float mShotTime;

		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
}