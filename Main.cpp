#include"GameManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    App::GameManager* gameManager = new App::GameManager();
    gameManager->Init();
    gameManager->Loop();
    gameManager->Finalize();

    return 0;
}