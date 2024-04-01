#pragma once
#include "tinyxml2.h"
#include "../Data/TitleScreenData.h"
#include "../Data/PlayerData.h"
#include "../Data/StageData.h"
#include <map>
#include <vector>

namespace Raiden
{
	class XmlReader
	{
	public:
		void Init();
		TitleScreenData ParseTitleScreen() const;
		std::vector<StageData> ParseStages();
		PlayerData ParsePlayer() const;

	private:
		// Tools
		tinyxml2::XMLElement *LoadXml(std::string file_name) const;
		tinyxml2::XMLElement *ParseXmlChild(tinyxml2::XMLElement *elem, std::string tag) const;
		tinyxml2::XMLElement *ParseXmlNext(tinyxml2::XMLElement *elem, std::string tag) const;
		std::vector<tinyxml2::XMLElement *> ParseXmlList(tinyxml2::XMLElement *elem, std::string tag) const;
		tinyxml2::XMLElement *ParseXmlDown(tinyxml2::XMLElement *elem, std::vector<std::string> tags) const;
		int ParseXmlInt(tinyxml2::XMLElement *elem) const;
		std::string ParseXmlText(tinyxml2::XMLElement *elem) const;

		// XML element parsers
		std::string ParsePathElem(tinyxml2::XMLElement *path_elem) const;
		std::tuple<int, int, int> ParseColorMaskElem(tinyxml2::XMLElement *color_mask_elem) const;
		std::vector<std::string> ParseSpriteElems(std::string path, std::vector<tinyxml2::XMLElement *> sprite_elems) const;
		CPoint ParsePositionElem(tinyxml2::XMLElement *position_elem) const;
		std::vector<CPoint> ParsePositionElems(std::vector<tinyxml2::XMLElement *> position_elems) const;

		// Data readers
		BackgroundData ParseStageBackground(std::string stage);
		std::vector<FighterData> ParseFighters(std::string stage);

		// Document root elements
		tinyxml2::XMLElement *game_setting_elem;
		std::map<std::string, tinyxml2::XMLElement *> stage_elems;
	};
}
