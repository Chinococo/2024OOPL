#pragma once
#include "tinyxml2.h"
#include <map>
#include <vector>

namespace Raiden
{
	struct Enemy_temp
	{
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

	struct Figter_temp
	{
		int x;
		int y;
		int startMoveTime;
		int tick;
		int positionIndex;
		Figter_temp(int x_, int y_, int startMoveTime_, int tick_, int positionIndex_) :
			x(x_), y(y_), startMoveTime(startMoveTime_), tick(tick_), positionIndex(positionIndex_) {}
	};

	struct XmlReader
	{
	public:
		std::map<std::string, std::string> ParseResourcesRootPath(tinyxml2::XMLElement* root);
		std::vector<Enemy_temp> ParseEnemies(tinyxml2::XMLElement* root);
		std::vector<Figter_temp> ParseFigter(tinyxml2::XMLElement* root);
	};
}
