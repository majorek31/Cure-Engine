#pragma once
namespace Cure {
	class AssetManager
	{
	public:
		static AssetManager& Get();
	private:
		static AssetManager* s_Instance;
	};
}

