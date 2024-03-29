#pragma once
#include "../Player/Player.h"
#include "../Background/Background.h"
#include "../Boss/Boss.h"
#include <set>
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
		virtual void UpdateDerived(const Player &player) = 0;
		virtual void ShowDerived() = 0;
		Background background;
		std::unique_ptr<Boss> boss;
	};
}
