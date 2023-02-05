#pragma once
#include"DxLib.h"
#include"Math.h"
#include"Collision.h"
#include"GameObject.h"

#define ENEMY_SHOT_FRAME 500

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

		Lib::Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		const float shotInterval =  500.0f;
		const float beamInterval = 1500.0f;
		float mShotTime;
		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
}