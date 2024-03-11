#pragma once
#include "../AnimatedBitmap/AnimatedBitmap.hpp"

namespace Raiden
{
	class Player
	{
	public:
		void Init();
		void Update();
		void Show();

	private:
		AnimatedBitmap sprite;
	};
}
