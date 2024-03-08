#pragma once
#include "../Background/Background.hpp"

namespace Raiden
{
	class Stage
	{
	public:
		virtual ~Stage() = default;
		virtual void Init() = 0;
		bool Update(); // Returns true if the current stage is completed.
		void Show();

	protected:
		Background background;
		
	};
}
