#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <iostream>

struct MapInfo
{
	std::vector<std::string> map;
	int len;
	char empty;
	char obstacle;
	char full;
};

inline std::ostream &operator<<(std::ostream &os, const MapInfo &mapInfo)
{
	for (const std::string &line : mapInfo.map)
	{
		os << line << std::endl;
	}
	return os;
}

MapInfo readMap(char *argv[]);
MapInfo putMaxSquare(MapInfo map);
