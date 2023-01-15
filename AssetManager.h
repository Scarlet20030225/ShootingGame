#pragma once
#include<string>
#include<unordered_map>
#include<atlstr.h>
#include<DxLib.h>

namespace App
{
	class AssetManager final
	{
	public:
		static void Init();
		static int GetMesh(std::string meshFileName);
		static int GetAnimation(std::string animationFileName);
		static void ReleaseMesh(int meshID);
		static void ReleaseAllAsset();
		static void Finalize();

	private:
		AssetManager();
		~AssetManager();

		static AssetManager* mpInstance;

		std::unordered_map<std::string, int>mMeshMap;
		std::unordered_map<std::string, int>mAnimationMap;
		std::vector<int>mDuplicatesMesh;
	};
}