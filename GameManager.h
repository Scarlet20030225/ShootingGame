#pragma once
#include"DxLib.h"
#include"GameState.h"
#include"CollisionDetection.h"
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
		Player*     player;
		PlayerShot* playerShot;
		Boss*       boss;
		BossShot*   bossShot;
		GameState*  gameState;
		Camera*     camera;
		CollisionDetection* collisionDetection;

		// �E�B���h�E�֘A
		int screenSizeX   = 1920;	// �X�N���[����
		int screenSizeY   = 1080;	// �X�N���[������
		int colorBitDepth =   32;	// �J���[�r�b�g��

		// �t���[���֘A
		int fps;
		int deltaTime;
	};
}