#pragma once
#include"DxLib.h"
#include"Math.h"
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

	private:
		const float mSpeed			 = 500.0f;	// �v���C���[�̑��x
		const float mRapidInterval   =   0.2f;	// �}�V���K���̔��ˊԊu
		const float mHomingInterval  =   0.6f;	// �z�[�~���O�e�̔��ˊԊu
		const float mMissileInterval =   1.1f;	// �~�T�C���̔��ˊԊu
		float mShotTime;
	};
}