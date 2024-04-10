#include "../inc/bsq.hpp"

extern int g_max;
extern int g_col;
extern int g_row;

static bool check_put_square(char **map, t_temps *temp, t_info *info)
{
    int i;

    i = 0;
    while (i <= temp->size)
    {
        if (temp->col + i == count_map_colsize(map))
            return (false);
        if (temp->row + i == info->num_rows + 1)
            return (false);
        if (map[temp->row][temp->col + i] == info->obstacle || map[temp->row][temp->col + i] == '\0')
            return (false);
        if (map[temp->row + i][temp->col] == info->obstacle || map[temp->row + i][temp->col] == '\0')
            return (false);
        i++;
    }
    return (true);
}

static void check_put_square(char **map, t_temps *temp, t_info *info)
{
    temp->size = 0;
    while (check_update_square(map, temp, info) == true)
        temp->size++;
    if (g_max < temp->size)
    {
        g_max = temp->size;
        g_col = temp->col;
        g_row = temp->row;
    }
}

static void put_map(char **map, t_info *info)
{
    int i;
    int j;

    i = 1;
    while (i <= info->num_rows)
    {
        j = 0;
        while (j < count_map_colsize(map))
        {
            write(1, &map[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

static void make_square_on_map(char **map, t_info *info)
{
    int i;
    int j;

    i = 0;
    while (i < g_max)
    {
        j = 0;
        while (j < g_max)
        {
            map[g_row + i][g_col + j] = info->full;
            j++;
        }
        i++;
    }
    return;
}

void ft_make_map(char **map, t_info *info)
{
    t_temps temp;

    g_max = 0;
    g_col = 0;
    g_row = 0;
    set_temps(&temp);
    while (temp.row <= info->num_rows)
    {
        temp.col = 0;
        while (temp.col < count_map_colsize(map))
        {
            if (check_put_full(map, temp.col, temp.row, info) == true)
                update_max_square(map, &temp, info);
            temp.col++;
        }
        temp.row++;
    }
    make_square_on_map(map, info);
    put_map(map, info);
    return;
}
