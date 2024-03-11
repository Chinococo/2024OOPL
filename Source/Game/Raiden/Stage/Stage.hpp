#pragma once
#include "../Background/Background.hpp"
#include "../AnimatedBitmap/AnimatedBitmap.hpp"

namespace Raiden
{
	class Stage
	{
	public:
		void Init();
		void Update();
		void Show();
		bool Over();

	private:
		Background background;
	};
}
