#include "stdafx.h"
#include "XmlReader.h"
#include <string>
#include <exception>

namespace Raiden
{
	void XmlReader::Init()
	{
		game_setting_elem = LoadXml("GameSetting");
		stage_elems["StageJapan"] = LoadXml("StageJapan");
		stage_elems["StageBrazil"] = LoadXml("StageBrazil");
		stage_elems["StageUSA"] = LoadXml("StageUSA");
	}

	tinyxml2::XMLElement *XmlReader::LoadXml(std::string file_name) const
	{
		std::string file = "Resources/Xml/" + file_name + ".xml";

		tinyxml2::XMLDocument doc;

		if (doc.LoadFile(file.c_str()) != tinyxml2::XML_SUCCESS)
			throw std::runtime_error("Invalid XML file: " + file_name + ".");

		return doc.RootElement();
	}

	tinyxml2::XMLElement *XmlReader::ParseXmlChild(tinyxml2::XMLElement *elem, std::string tag) const
	{
		auto child_elem = elem->FirstChildElement(tag.c_str());

		if (!child_elem)
			throw std::runtime_error("Invalid XML child element: " + tag + ".");

		return child_elem;
	}

	tinyxml2::XMLElement *XmlReader::ParseXmlNext(tinyxml2::XMLElement *elem, std::string tag) const
	{
		auto next_elem = elem->NextSiblingElement(tag.c_str());

		if (!next_elem)
			throw std::runtime_error("Invalid XML next element: " + tag + ".");

		return next_elem;
	}

	std::vector<tinyxml2::XMLElement *> XmlReader::ParseXmlList(tinyxml2::XMLElement *elem, std::string tag) const
	{
		auto current_elem = ParseXmlChild(elem, tag);

		std::vector<tinyxml2::XMLElement *> list;

		while (current_elem)
		{
			list.push_back(current_elem);

			current_elem = ParseXmlNext(current_elem, tag);
		}

		return list;
	}

	tinyxml2::XMLElement *XmlReader::ParseXmlDown(tinyxml2::XMLElement *elem, std::vector<std::string> tags) const
	{
		for (const auto &tag : tags)
			elem = ParseXmlChild(elem, tag);
		
		return elem;
	}

	int XmlReader::ParseXmlInt(tinyxml2::XMLElement *elem) const
	{
		int content = 0;
		elem->QueryIntText(&content);

		return content;
	}

	std::string XmlReader::ParseXmlText(tinyxml2::XMLElement *elem) const
	{
		return elem->GetText();
	}

	PlayerData XmlReader::ParsePlayer() const
	{
		auto path_elem = ParseXmlChild(game_setting_elem, { "Player", "Path" });
		auto color_mask_elem = ParseXmlDown(game_setting_elem, { "Player", "ColorMask" });
		auto sprite_elems = ParseXmlList(ParseXmlDown(game_setting_elem, { "Player", "Sprites" }), "Sprite");
		auto init_position_elem = ParseXmlDown(game_setting_elem, { "Player", "InitPosition" });

		PlayerData player_data;
		player_data.color_mask = ParseColorMaskElem(color_mask_elem);
		player_data.sprites = ParseSpriteElems(ParsePathElem(path_elem), sprite_elems);
		player_data.init_position = ParsePositionElem(init_position_elem);

		return player_data;
	}

	TitleScreenData XmlReader::ParseTitleScreen() const
	{
		auto path_elem = ParseXmlChild(game_setting_elem, { "Background", "Path" });
		auto animation_delay_milli_elem = ParseXmlDown(game_setting_elem, { "TitleScreen", "AnimationDelayMilli" });
		auto left_margin_elem = ParseXmlDown(game_setting_elem, { "Background", "LeftMargin" });
		auto sprite_elems = ParseXmlList(ParseXmlDown(game_setting_elem, { "Background", "Sprites" }), "Sprite");

		auto selection_line_sprite_elems = ParseXmlList(ParseXmlDown(game_setting_elem, { "SelectionLine", "Sprites" }), "Sprite");
		auto selection_line_position_elems = ParseXmlList(ParseXmlDown(game_setting_elem, { "SelectionLine", "Positions" }), "Position");

		TitleScreenData title_screen_data;
		title_screen_data.animation_delay_milli = ParseXmlInt(animation_delay_milli_elem);
		title_screen_data.left_margin = ParseXmlInt(left_margin_elem);
		title_screen_data.sprites = ParseSpriteElems(ParsePathElem(path_elem), sprite_elems);

		title_screen_data.selection_line_data.sprites = ParseSpriteElems(ParsePathElem(path_elem), selection_line_sprite_elems);
		title_screen_data.selection_line_data.positions = ParsePositionElems(selection_line_position_elems);

		return title_screen_data;
	}

	std::vector<StageData> XmlReader::ParseStages()
	{
		std::vector<StageData> stages_data;

		for (const auto &item : stage_elems)
		{
			std::string stage = item.first;

			StageData stage_data;
			stage_data.background_data = ParseStageBackground(stage);
			stage_data.fighters_data = ParseFighters(stage);

			stages_data.push_back(stage_data);
		}

		return stages_data;
	}

	BackgroundData XmlReader::ParseStageBackground(std::string stage)
	{
		auto path_elem = ParseXmlChild(game_setting_elem, { "Background", "Path" });
		auto scroll_step_elem = ParseXmlDown(game_setting_elem, { "Background", "ScrollStep" });
		auto scroll_interval_milli_elem = ParseXmlDown(game_setting_elem, { "Background", "ScollIntervalMilli" });
		auto sprite_elems = ParseXmlList(ParseXmlDown(stage_elems[stage], { "Background", "Sprites" }), "Sprite");

		BackgroundData background_data;
		background_data.scroll_step = ParseXmlInt(scroll_step_elem);
		background_data.scroll_interval_milli = ParseXmlInt(scroll_interval_milli_elem);
		background_data.sprites = ParseSpriteElems(ParsePathElem(path_elem), sprite_elems);

		return background_data;
	}

	std::vector<FighterData> XmlReader::ParseFighters(std::string stage)
	{
		auto path_elem = ParseXmlDown(game_setting_elem, { "Fighters", "Path" });
		auto color_mask_elem = ParseXmlDown(game_setting_elem, { "Fighters", "ColorMask" });
		auto sprite_elems = ParseXmlList(ParseXmlDown(game_setting_elem, { "Fighters", "Sprites" }), "Sprite");
		auto fighter_elems = ParseXmlList(ParseXmlChild(stage_elems[stage], "Fighters"), "Fighter");

		auto color_mask = ParseColorMaskElem(color_mask_elem);
		auto sprites = ParseSpriteElems(ParsePathElem(path_elem), sprite_elems);

		std::vector<FighterData> fighters_data;

		for (const auto &fighter_elem : fighter_elems)
		{
			auto appear_distance_elem = ParseXmlChild(fighter_elem, "AppearDistance");
			auto move_interval_milli_elem = ParseXmlChild(fighter_elem, "MoveIntervalMilli");
			auto position_elems = ParseXmlList(ParseXmlChild(fighter_elem, "Positions"), "Position");

			FighterData fighter_data;
			fighter_data.appear_distance = ParseXmlInt(appear_distance_elem);
			fighter_data.move_interval_milli = ParseXmlInt(move_interval_milli_elem);
			fighter_data.color_mask = color_mask;
			fighter_data.sprites = sprites;
			fighter_data.positions = ParsePositionElems(position_elems);

			fighters_data.push_back(fighter_data);
		}

		return fighters_data;
	}

	std::string XmlReader::ParsePathElem(tinyxml2::XMLElement *path_elem) const
	{
		auto root_path_elem = ParseXmlChild(game_setting_elem, "RootPath");

		return ParseXmlText(root_path_elem) + ParseXmlText(path_elem);
	}

	std::tuple<int, int, int> XmlReader::ParseColorMaskElem(tinyxml2::XMLElement *color_mask_elem) const
	{
		auto red_elem = ParseXmlChild(color_mask_elem, "Red");
		auto green_elem = ParseXmlChild(color_mask_elem, "Green");
		auto blue_elem = ParseXmlChild(color_mask_elem, "Blue");

		return std::make_tuple(ParseXmlInt(red_elem), ParseXmlInt(green_elem), ParseXmlInt(blue_elem));
	}

	std::vector<std::string> XmlReader::ParseSpriteElems(std::string path, std::vector<tinyxml2::XMLElement *> sprite_elems) const
	{
		std::vector<std::string> sprites;

		for (const auto &sprite_elem : sprite_elems)
			sprites.push_back(path + ParseXmlText(sprite_elem));

		return sprites;
	}

	CPoint XmlReader::ParsePositionElem(tinyxml2::XMLElement *position_elem) const
	{
		auto left_elem = ParseXmlChild(position_elem, "Left");
		auto top_elem = ParseXmlChild(position_elem, "Top");

		return { ParseXmlInt(left_elem), ParseXmlInt(top_elem) };
	}

	std::vector<CPoint> XmlReader::ParsePositionElems(std::vector<tinyxml2::XMLElement *> position_elems) const
	{
		std::vector<CPoint> positions;

		for (const auto &position_elem : position_elems)
			positions.push_back(ParsePositionElem(position_elem));

		return positions;
	}
}
