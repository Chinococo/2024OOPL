#pragma once
#include <vector>
#include <string>

namespace Raiden
{
	struct AnimationSetting
	{
		std::vector<std::string> frames;
		int delay;
		bool once;
	};
}
