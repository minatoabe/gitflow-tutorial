#pragma once

#include <iostream>
#include <vector>
#include <cstring>

struct Map
{
	std::vector<std::string> map;
	int len;
	char empty;
	char obstacle;
	char full;
};
