#pragma once
#include <map>
#include "tinyxml2.h"
class XmlReader
{
	void ParseResourcesRootPath(tinyxml2::XMLElement* root, std::map<std::string, std::string>& settings);
	void ParseEnemies(tinyxml2::XMLElement* root, std::map<std::string, std::string>& settings);
};

