#pragma once
#include <vector>
#include "../Asset.h"

namespace Cure {
	class CURE_API AssetManager
	{
	public:
		static AssetManager& Get();

		Asset& LoadAsset(const std::string name, Asset* asset);
		void DestroyAsset(const std::string name);

		template<typename T>
		T* GetAsset(const std::string name)
		{
			for (const auto& asset : m_Assets)
			{
				if (asset->GetName() == name)
					return (T*)asset;
			}
			return nullptr;
		}
	private:
		AssetManager();
		AssetManager(AssetManager&) = delete;
		AssetManager(const AssetManager&) = delete;
		static AssetManager* s_Instance;
		std::vector<Asset*> m_Assets;
	};
}

