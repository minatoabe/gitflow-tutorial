#include "../inc/bsq.hpp"
#include "../inc/Map.hpp"

static MapInfo restoreMap(std::ifstream &file)
{
	std::string line;
	MapInfo mapInfo;

	std::getline(file, line);
	mapInfo.full = line[line.size() - 1];
	mapInfo.obstacle = line[line.size() - 2];
	mapInfo.empty = line[line.size() - 3];
	try
	{
		mapInfo.len = stoi(line.substr(0, line.size() - 3));
	}
	catch (const std::exception &e)
	{
		throw std::runtime_error("Invalid map");
	}
	if (mapInfo.len <= 0 || mapInfo.full == mapInfo.obstacle || mapInfo.obstacle == mapInfo.empty || mapInfo.empty == mapInfo.full)
	{
		throw std::runtime_error("Invalid map");
	}

	int rowCount = 0;
	while (std::getline(file, line) && !line.empty())
	{
		mapInfo.map.push_back(line);
		if (line.size() != static_cast<size_t>(mapInfo.len))
		{
			throw std::runtime_error("Invalid map");
		}
		rowCount++;
	}
	if (rowCount != mapInfo.len)
	{
		throw std::runtime_error("Invalid map");
	}
	return mapInfo;
}

MapInfo readMap(char *argv[])
{
	std::ifstream file;

	file.open(argv[1]);
	if (!file.is_open())
	{
		file.close();
		throw std::runtime_error("File not found");
	}
	else
	{
		try
		{
			MapInfo mapInfo = restoreMap(file);
			file.close();
			return mapInfo;
		}
		catch (const std::exception &e)
		{
			file.close();
			throw std::runtime_error("Invalid map");
		}
	}
}

MapInfo putMaxSquare(MapInfo mapInfo)
{

	return mapInfo;
}
