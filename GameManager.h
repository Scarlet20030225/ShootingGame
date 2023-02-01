#pragma once
#include"DxLib.h"
#include"Player.h"
#include"GameState.h"
#include"Camera.h"

namespace App
{
	class GameManager
	{
	public:
		GameManager();		// �R���X�g���N�^
		~GameManager();		// �f�X�g���N�^

		/// <summary>
		/// ������
		/// </summary>
		void Init();

		/// <summary>
		/// ���[�v
		/// </summary>
		void Loop();

		/// <summary>
		/// �㏈��
		/// </summary>
		void Finalize();

	private:
		Player* player;
		GameState* gameState;
		Camera* camera;

		int fps;
		int deltaTime;
	};
}