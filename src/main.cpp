#include "../inc/bsq.hpp"

static Map putMaxSquare(Map &map)
{
    Map result;
    std::vector<std::vector<int> > intMap;
    int max = 0;
    int maxX = 0;
    int maxY = 0;

    for (std::string line : map)
    {
        std::vector<int> intLine;
        for (char c : line)
        {
            if (c == '.')
            {
                intLine.push_back(1);
            }
            else
            {
                intLine.push_back(0);
            }
        }
        intMap.push_back(intLine);
    }

    for (size_t i = 1; i < intMap.size(); i++)
    {
        for (size_t j = 1; j < intMap[i].size(); j++)
        {
            if (intMap[i][j] == 1)
            {
                int min = std::min(intMap[i - 1][j], std::min(intMap[i][j - 1], intMap[i - 1][j - 1]));
                intMap[i][j] = min + 1;
                if (intMap[i][j] > max)
                {
                    max = intMap[i][j];
                    maxX = i;
                    maxY = j;
                }
            }
        }
    }

    for (int i = maxX - max; i < maxX; i++)
    {
        std::string line = map[i];
        for (int j = maxY - max; j < maxY; j++)
        {
            line[j] = 'x';
        }
        result.push_back(line);
    }

    return result;
}

static Map readMap(char *argv[])
{
    std::ifstream file;
    Map map;

    file.open(argv[1]);
    if (!file.is_open())
    {
        file.close();
        throw std::runtime_error("File not found");
    }
    else
    {
        std::string line;

        while (std::getline(file, line))
        {
            map.map.push_back(line);
        }
        file.close();
        return map;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " [map_file]" << std::endl;
    }
    else
    {
        try
        {
            Map map = readMap(argv);
            Map result = putMaxSquare(map);
            for (std::string line : result)
            {
                std::cout << line << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
