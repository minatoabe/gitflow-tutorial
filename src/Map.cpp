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
        throw std::runtime_error(" INVALID");
    }
    if (mapInfo.len <= 0 || mapInfo.full == mapInfo.obstacle || mapInfo.obstacle == mapInfo.empty || mapInfo.empty == mapInfo.full)
    {
        throw std::runtime_error(" INVALID");
    }

    int rowCount = 0;
    while (std::getline(file, line) && !line.empty())
    {
        mapInfo.map.push_back(line);
        if (line.size() != static_cast<size_t>(mapInfo.len))
        {
            throw std::runtime_error(" INVALID");
        }
        rowCount++;
    }
    if (rowCount != mapInfo.len)
    {
        throw std::runtime_error(" INVALID");
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
            throw std::runtime_error(" INVALID");
        }
    }
}

std::vector<std::string> putMaxSquare(MapInfo mapInfo)
{
    std::vector<std::string> result;
    // 動的計画法で最大の正方形を探す
    std::vector<std::vector<int>> dp(mapInfo.map.size(), std::vector<int>(mapInfo.map[0].size(), 0));
    size_t max = 0;
    size_t max_i = 0;
    printf("bbb");
    size_t max_j = 0;
    for (size_t i = 0; i < mapInfo.map.size(); i++)
    {
        for (size_t j = 0; j < mapInfo.map[i].size(); j++)
        {
            if (mapInfo.map[i][j] == mapInfo.obstacle)
            {
                printf("aaaa");
                dp[i][j] = 0;
            }
            else if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                printf("aaaa");
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            if (static_cast<size_t>(dp[i][j]) > max)
            {
                max = dp[i][j];
                printf("bbb");
                max_i = i;
                max_j = j;
            }
        }
    }
    for (size_t i = 0; i < mapInfo.map.size(); i++)
    {
        std::string line;
        for (size_t j = 0; j < mapInfo.map[i].size(); j++)
        {
            if (i >= max_i - max + 1 && i <= max_i && j >= max_j - max + 1 && j <= max_j)
            {
                line += mapInfo.full;
            }
            else
            {
                line += mapInfo.map[i][j];
            }
        }
        result.push_back(line);
    }
    printf("aaaa");
    return result;
}
