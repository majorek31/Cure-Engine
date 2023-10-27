#pragma once
#include <string>
#include "../Macros.h"

namespace Cure {
	class CURE_API Asset
	{
	public:
		virtual ~Asset() {}
		virtual size_t GetType() = 0;
		void SetNative(void* native);
		void* GetNative();
		const std::string& GetName();
	protected:
		void SetName(const std::string& name);
		void* m_NativeAsset;
		std::string m_Name;
		friend class AssetManager;
	};
}