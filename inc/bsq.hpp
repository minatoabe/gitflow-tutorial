#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define SUCCESS 1
#define FAIL 0
#define FT_ERR_MAP "map error\n"
#define INFO_MIN 4

typedef struct s_bsq
{
    int x;
    int y;
    int size;
} t_bsq;

typedef struct s_info
{
    int num_rows;
    char empty;
    char obstacle;
    char full;
} t_info;

typedef struct s_temps
{
    int col;
    int row;
    int size;
} t_temps;

int g_max;
int g_col;
int g_row;

t_info *init_mapinfo(char **map);

bool check_valid_map(char **map, t_info *info);
bool check_end_with_newline(char *content);
void set_temps(t_temps *temps);
bool check_put_full(char **map, int col, int row, t_info *info);
void ft_make_map(char **map, t_info *info);
int count_map_colsize(char **map);
