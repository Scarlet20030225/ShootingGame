#pragma once
#include"DxLib.h"
#include"math.h"
#include"Collision.h"
#include"GameObject.h"

namespace App
{
	class EnemyShot : public GameObject
	{
	public:
		EnemyShot();
		~EnemyShot();

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
		Lib::Sphere mCollisionSphere;		// �����蔻�苅
	};
}