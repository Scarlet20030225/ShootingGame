#include<windows.h>
#include"DxLib.h"
#include"AssetManager.h"
#include"GameObject.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Player.h"
#include"PlayerShot.h"
#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    //SetBackgroundColor(255, 255, 255);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // �J����
    SetCameraNearFar(1.0f, 2000.0f);
    SetCameraPositionAndTarget_UpVecY(VGet(960.0f, 540.0f, -1000.0f), VGet(960.0f, 540.0f, 0.0f));

    // ���C�g
    SetLightDirection(VGet(0.0f, 0.0f, 1.0f));
    SetLightPosition(VGet(960.0f, 540.0f, -1000.0f));

    App::GameObjectManager::Init();
    App::AssetManager::Init();

    App::Player* player = new App::Player;
    App::GameObjectManager::Entry(player);

    LONGLONG nowCount, prevCount;                      // �}�C�N���b(100������1�b�P�ʂŎ����擾)
    nowCount = prevCount = GetNowHiPerformanceCount();
    float fixedDeltaTime = 1.0f / 60.0f;               // 60����1�b = 0.01666...�b
    float waitFrameTime = 15500;                       // 16000�}�C�N���b = 16�~���b = 0.016�b


    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        float deltaTime;
        nowCount = GetNowHiPerformanceCount();
        deltaTime = (nowCount - prevCount) / 1000000.0f;

        App::GameObjectManager::Update(deltaTime);

        //��ʍX�V����
        ClearDrawScreen();

        char buf[256];
        //sprintf(buf, "deltaTime = %f, FPS : %f", deltaTime, 1.0f / deltaTime);
        DrawString(0, 0, buf, GetColor(255, 255, 255));

        App::GameObjectManager::Draw();

        ScreenFlip();

        while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
        {
            ;
        }
        prevCount = nowCount;
        QueryPerformanceCounter(&end);

        double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
        sprintf(buf, "�o�ߎ��ԁF%lf[ms]\n", time);
    }
    App::GameObjectManager::Finalize();
    App::AssetManager::Finalize();

    DxLib_End();
    return 0;
}