#include"GameObjectManager.h"
#include"GameObject.h"

namespace App
{
	GameObjectManager* GameObjectManager::mpInstance = nullptr;

	GameObjectManager::GameObjectManager()
		: mObjects()
	{
		mpInstance = nullptr;
	}

	GameObjectManager::~GameObjectManager()
	{
		ReleaseAllObj();
	}

	void GameObjectManager::Init()
	{
		if (!mpInstance)
		{
			mpInstance = new GameObjectManager;
		}
	}

	void GameObjectManager::Entry(GameObject* newObj)
	{
		mpInstance->mPendingObjects.emplace_back(newObj);
	}

	void GameObjectManager::Release(GameObject* releaseObj)
	{
		auto iter = std::find(mpInstance->mPendingObjects.begin(),
			mpInstance->mPendingObjects.end(), releaseObj);
		if (iter != mpInstance->mPendingObjects.end())
		{
			std::iter_swap(iter, mpInstance->mPendingObjects.end() - 1);
			mpInstance->mPendingObjects.pop_back();

			return;
		}

		iter = std::find(mpInstance->mObjects.begin(), mpInstance->mObjects.end(), releaseObj);
		if (iter != mpInstance->mObjects.end())
		{
			std::iter_swap(iter, mpInstance->mObjects.end() - 1);
			delete mpInstance->mObjects.back();
		}
	}

	void GameObjectManager::ReleaseAllObj()
	{
		while (!mpInstance->mPendingObjects.empty())
		{
			delete mpInstance->mPendingObjects.back();
		}

		while (!mpInstance->mObjects.empty())
		{
			delete mpInstance->mObjects.back();
			mpInstance->mObjects.pop_back();
		}
	}

	void GameObjectManager::Update(float deltaTime)
	{
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Update(deltaTime);
		}

		for (auto pending : mpInstance->mPendingObjects)
		{
			mpInstance->mObjects.emplace_back(pending);
		}

		mpInstance->mPendingObjects.clear();

		std::vector<GameObject*> deadObjects;

		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			if (!mpInstance->mObjects[i]->GetAlive())
			{
				deadObjects.emplace_back(mpInstance->mObjects[i]);
			}
		}

		for (auto deadObj : deadObjects)
		{
			delete deadObj;
		}
		deadObjects.clear();
	}

	void GameObjectManager::Draw()
	{
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Draw();
		}
	}

	void GameObjectManager::Finalize()
	{
		ReleaseAllObj();
		if (mpInstance)
		{
			delete mpInstance;
			mpInstance = nullptr;
		}
	}
}