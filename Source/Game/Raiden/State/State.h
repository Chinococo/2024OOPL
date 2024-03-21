#pragma once
#include "../Control/Control.h"

namespace Raiden
{
	class State
	{
	public:
		virtual ~State() = default;
		virtual void Init() = 0;
		virtual void Update(Control &&control) = 0;
		virtual void Show() = 0;
		virtual bool Over() = 0;
	};
}
