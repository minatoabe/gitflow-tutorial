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
            std::cout << mapInfo << std::endl;
            MapInfo result = putMaxSquare(mapInfo);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
