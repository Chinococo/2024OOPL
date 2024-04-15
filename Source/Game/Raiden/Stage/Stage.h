#pragma once
#include "../Player/Player.h"
#include "../Background/Background.h"
#include "../Fighter/Fighter.h"
#include "../Boss/Boss.h"
#include "../Data/StageData.h"
#include <set>
#include <memory>

namespace Raiden
{
	class Stage
	{
	public:
		virtual ~Stage() = default;
		void Init(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>>fighters);
		void Update(const Player &player);
		void Show();
		bool Over() const;

	protected:
		virtual void InitDerived(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>> fighters) = 0;
		virtual void UpdateDerived(const Player &player) = 0;
		Background background;
		std::unique_ptr<Boss> boss;
	};
}
