#include<chrono>
#include<thread>

#include"GameManager.h"
#include"AssetManager.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Title.h"
#include"OperationMethod.h"
#include"GamePlay.h"
#include"Result.h"
#include"PlayerShot.h"

#pragma warning(disable:4996)

namespace App
{
    GameManager::GameManager()
    {
    }

    GameManager::~GameManager()
    {
        delete player;
        delete gameState;

        player    = nullptr;
        gameState = nullptr;
    }

    void GameManager::Init()
    {
        // DxLib������
        ChangeWindowMode(TRUE);
        DxLib_Init();
        SetGraphMode(screenSizeX, screenSizeY, colorBitDepth);
        //SetBackgroundColor(255, 255, 255);

        App::GameObjectManager::Init();
        App::AssetManager::Init();

        player    = new App::Player();
        gameState = new App::Title();
        camera    = new App::Camera();

        App::GameObjectManager::Entry(player);

        // �t���[����60fps��
        fps = 60;
        deltaTime = 1000 / fps;
    }

    void GameManager::Loop()
    {
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            // �����J�n����������
            auto start = std::chrono::system_clock::now();

            // Update����
            //gameState->Update(deltaTime);
            App::GameObjectManager::Update(deltaTime);

            //��ʍX�V����
            ClearDrawScreen();

            // �`�揈��
            //gameState->Draw();
            App::GameObjectManager::Draw();

            // �`����m��
            ScreenFlip();

            // 1�t���[���ɂ����鎞�Ԃ��v�Z
            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            // 1�t���[���ɂ����������Ԃ��w��̎��Ԉȉ��ł���Αҋ@����
            if (elapsed.count() < deltaTime)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime - elapsed.count()));
            }
        }
    }

    void GameManager::Finalize()
    {
        App::GameObjectManager::Finalize();
        App::AssetManager::Finalize();

        // ���C�u�����I������
        DxLib_End();
    }
}