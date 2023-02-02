#pragma once
#include"DxLib.h"
#include"Player.h"
#include"Boss.h"
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
		Boss* boss;
		GameState* gameState;
		Camera* camera;

		// �E�B���h�E�֘A
		int screenSizeX   = 1920;	// �X�N���[����
		int screenSizeY   = 1080;	// �X�N���[������
		int colorBitDepth =   32;	// �J���[�r�b�g��

		// �t���[���֘A
		int fps;
		int deltaTime;
	};
}