#pragma once
#include "../Player/Player.h"
#include "../Background/Background.h"
#include "../Enemy/Enemy.h"
#include "../Boss/Boss.h"
#include <set>
#include <vector>
#include <memory>

namespace Raiden
{
	class Stage
	{
	public:
		virtual ~Stage() = default;
		virtual void Init() = 0;
		void Update(const Player &player);
		void Show();
		bool Over() const;

	protected:
		Background background;
		std::vector<Enemy> enemies;
		std::unique_ptr<Boss> boss;
	};
}
