#include "Asset.h"
namespace Cure {
	void Asset::SetNative(void* native) { m_NativeAsset = native; }

	void* Asset::GetNative() { return m_NativeAsset; }

	void Asset::SetName(const std::string& name) { m_Name = name; }

	const std::string& Asset::GetName() { return m_Name; }

}