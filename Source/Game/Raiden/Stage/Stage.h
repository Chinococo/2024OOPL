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
		void Init(StageData &&stage_data, shared_ptr<GameObjectPool<Fighter>>fighters, shared_ptr<GameObjectPool<Bullet>>bullets);
		void Update(const Player &player);
		void Show(bool debug);
		bool Over() const;
		std::shared_ptr<Boss> GetBoss();
	protected:
		virtual void InitDerived(StageData &&stage_data,shared_ptr<GameObjectPool<Fighter>> fighters, std::shared_ptr<GameObjectPool<Bullet>> bullets) = 0;
		virtual void UpdateDerived(const Player &player) = 0;
		Background background;
		std::shared_ptr<Boss> boss;
	};
}
