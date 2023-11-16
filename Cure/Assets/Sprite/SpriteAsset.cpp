#include "SpriteAsset.h"
#include <typeinfo>
namespace Cure {
	size_t SpriteAsset::GetType()
	{
		return typeid(*this).hash_code();
	}
}