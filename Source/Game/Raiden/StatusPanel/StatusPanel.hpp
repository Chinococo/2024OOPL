#pragma once
#include "Status.hpp"

namespace Raiden
{
	class StatusPanel
	{
	public:
		void Init();
		bool Update(bool settle, Status status);
		void Show();
	};
}
