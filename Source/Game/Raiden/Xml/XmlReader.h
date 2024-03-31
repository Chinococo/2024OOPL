#pragma once
#include "tinyxml2.h"
#include "../PlayerData/PlayerData.h"
#include "../FighterData/FighterData.h"
#include <map>
#include <vector>

namespace Raiden
{
	class XmlReader
	{
	public:
		void Init();
		PlayerData ParsePlayerData();
		std::vector<FighterData> ParseFightersData(std::string stage);

	private:
		// Tools
		tinyxml2::XMLElement *LoadXml(std::string file_name);
		tinyxml2::XMLElement *ParseXmlChild(tinyxml2::XMLElement *elem, std::string tag);
		tinyxml2::XMLElement *ParseXmlNext(tinyxml2::XMLElement *elem, std::string tag);
		std::vector<tinyxml2::XMLElement *> ParseXmlList(tinyxml2::XMLElement *elem, std::string tag);
		tinyxml2::XMLElement *ParseXmlDown(tinyxml2::XMLElement *elem, std::vector<std::string> tags);
		int ParseXmlInt(tinyxml2::XMLElement *elem);
		std::string ParseXmlText(tinyxml2::XMLElement *elem);

		// Parsers
		std::string ParsePathElem(tinyxml2::XMLElement *path_elem);
		std::tuple<int, int, int> ParseColorMaskElem(tinyxml2::XMLElement *color_mask_elem);
		std::vector<std::string> ParseSpriteElems(std::string path, std::vector<tinyxml2::XMLElement *> sprite_elems);
		CPoint ParsePositionElem(tinyxml2::XMLElement *position_elem);
		std::vector<CPoint> ParsePositionElems(std::vector<tinyxml2::XMLElement *> position_elems);

		// Document root elements
		tinyxml2::XMLElement *game_setting_elem;
		std::map<std::string, tinyxml2::XMLElement *> stage_elems;
	};
}
