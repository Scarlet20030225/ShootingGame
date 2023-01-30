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
		const float mSpeed		  = 500.0f;	// �v���C���[�̑��x
		const float mShotInterval = 1.03f;	// �e�̔��ˊԊu
		float mShotTime;
	};
}