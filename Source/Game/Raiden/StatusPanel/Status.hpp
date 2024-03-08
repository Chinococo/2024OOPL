#pragma once

namespace Raiden
{
	class Status
	{
	public:
		virtual ~Status() = default;
		int health = 0;
		int score = 0;
		int high_score = 0;
		int bomb_count = 0;
	};
}
