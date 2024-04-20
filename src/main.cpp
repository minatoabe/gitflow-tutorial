#include "../inc/bsq.hpp"

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
            MapInfo mapInfo = readMap(argv);
            std::vector<std::string> result = putMaxSquare(mapInfo);
            for (const std::string &line : result)
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
