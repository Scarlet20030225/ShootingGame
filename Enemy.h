#pragma once
#include"DxLib.h"
#include"Math.h"
#include"GameObject.h"

namespace App
{
	class Enemy : public GameObject
	{
	public:
		Enemy();
		~Enemy();

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

	};
}