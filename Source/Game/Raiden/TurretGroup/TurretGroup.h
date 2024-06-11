#pragma once
#include "../GameObjectPool/GameObjectPool.h"
#include "../Bullet/Bullet.h"
#include "../Turret/Turret.h"
#include <vector>
#include <memory>
namespace Raiden{
	class TurretGroup {
	public:
		TurretGroup(std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullets);
		void LoadFromXML(const std::string& filename);
		void update(CPoint now);

	private:
		std::vector<Turret> turrets;
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
};
	}