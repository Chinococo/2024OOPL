#pragma once
#include <map>
#include "tinyxml2.h"
#include "../Enemy/Enemy.h"
namespace Raiden{
	class Enemy_temp {
	public:
		int x;
		int y;
		int startMoveTime;
		int tick;
		int positionIndex;
		Enemy_temp(int x_, int y_, int startMoveTime_, int tick_, int positionIndex_) :
			x(x_), y(y_), startMoveTime(startMoveTime_), tick(tick_), positionIndex(positionIndex_) {}
		Enemy_temp(int x_, int y_) :
			x(x_), y(y_) {}
	};
	class Figter_temp {
	public:
		int x;
		int y;
		int startMoveTime;
		int tick;
		int positionIndex;
		Figter_temp(int x_, int y_, int startMoveTime_, int tick_, int positionIndex_) :
			x(x_), y(y_), startMoveTime(startMoveTime_), tick(tick_), positionIndex(positionIndex_) {}
	};
	class XmlReader
	{
	public:
		void ParseResourcesRootPath(tinyxml2::XMLElement* root, std::map<std::string, std::string>& settings);
		void ParseEnemies(tinyxml2::XMLElement* root, vector<Enemy_temp>& Enemys);
		void ParseFigter(tinyxml2::XMLElement* root, std::vector<Figter_temp>& Figter);
	};
}
