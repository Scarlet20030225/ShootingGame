#include"AssetManager.h"
#include<string>

namespace App
{
	AssetManager* AssetManager::mpInstance = nullptr;

	AssetManager::AssetManager()
	{
		mpInstance = nullptr;
	}

	AssetManager::~AssetManager()
	{
		mpInstance->ReleaseAllAsset();
		mpInstance = nullptr;
	}

	void AssetManager::Init()
	{
		if (!mpInstance)
		{
			mpInstance = new AssetManager;
		}
	}

	int AssetManager::GetMesh(std::string meshFileName)
	{
		int meshId = 0;

		auto iter = mpInstance->mMeshMap.find(meshFileName);

		if (iter == mpInstance->mMeshMap.end())
		{
			meshId = MV1LoadModel(meshFileName.c_str());
			if (meshId == -1)
			{
				return meshId;
			}
			mpInstance->mMeshMap.emplace(meshFileName, meshId);
		}

		meshId = MV1DuplicateModel(mpInstance->mMeshMap[meshFileName]);
		mpInstance->mDuplicatesMesh.push_back(meshId);

		return meshId;
	}

	int AssetManager::GetAnimation(std::string animationFileName)
	{
		int animId = 0;
		auto iter = mpInstance->mAnimationMap.find(animationFileName);

		if (iter == mpInstance->mAnimationMap.end())
		{
			animId = MV1LoadModel(animationFileName.c_str());
			if (animId == -1)
			{
				return animId;
			}
			mpInstance->mAnimationMap.emplace(animationFileName, animId);
		}

		return mpInstance->mAnimationMap[animationFileName];
	}

	void AssetManager::ReleaseMesh(int meshID)
	{
		auto iter = std::find(mpInstance->mDuplicatesMesh.begin(), mpInstance->mDuplicatesMesh.end(), meshID);
		if (iter == mpInstance->mDuplicatesMesh.end())
		{
			return;
		}

		MV1DeleteModel(meshID);

		std::iter_swap(iter, mpInstance->mDuplicatesMesh.end() - 1);
		mpInstance->mDuplicatesMesh.pop_back();
	}

	void AssetManager::ReleaseAllAsset()
	{
		for (auto iter = mpInstance->mAnimationMap.begin(); iter != mpInstance->mAnimationMap.end(); ++iter)
		{
			MV1DeleteModel(iter->second);
		}
		for (auto iter = mpInstance->mMeshMap.begin(); iter != mpInstance->mMeshMap.end(); ++iter)
		{
			MV1DeleteModel(iter->second);

		}
		for (auto iter = mpInstance->mDuplicatesMesh.begin(); iter != mpInstance->mDuplicatesMesh.end(); ++iter)
		{
			MV1DeleteModel(*iter);
		}

		mpInstance->mAnimationMap.clear();
		mpInstance->mMeshMap.clear();
		mpInstance->mDuplicatesMesh.clear();
	}

	void AssetManager::Finalize()
	{
		ReleaseAllAsset();
		if (mpInstance)
		{
			delete mpInstance;
		}
	}
}