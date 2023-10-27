#include "AssetManager.h"
namespace Cure {
	AssetManager* AssetManager::s_Instance = nullptr;
	AssetManager::AssetManager() {}
	AssetManager& AssetManager::Get()
	{
		if (!s_Instance)
			s_Instance = new AssetManager();
		return *s_Instance;
	}
	Asset& AssetManager::LoadAsset(const std::string name, Asset* asset)
	{
		asset->SetName(name);
		m_Assets.push_back(asset);
		return *asset;
	}

	void AssetManager::DestroyAsset(const std::string name)
	{
		for (const auto& asset : m_Assets)
		{
			if (asset->GetName() == name)
				delete asset;
		}
	}
}