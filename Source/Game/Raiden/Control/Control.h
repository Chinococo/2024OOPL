#pragma once
#include "../Key/Key.h"
#include <set>
#include <atltypes.h>

namespace Raiden
{
	enum class ControlMode
	{
		KEYBOARD,
		MOUSE
	};

	struct Control
	{
		std::set<Key> keys;
		CPoint point;
		ControlMode mode;
	};
}
