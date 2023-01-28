#include"GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    App::GameManager* gameManager = new App::GameManager();
    gameManager->Init();
    gameManager->Loop();
    gameManager->Finalize();

    return 0;
}