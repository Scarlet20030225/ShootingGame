#pragma once
#include"DxLib.h"
#include"Math.h"
#include"GameObject.h"

namespace App
{
	class Boss : public GameObject
	{
	public:
		Boss();
		~Boss();

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
		const float shotInterval =  350.0f;
		const float beamInterval = 1500.0f;
		float mShotTime;
	};
}