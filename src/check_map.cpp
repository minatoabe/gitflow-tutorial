#include "../inc/bsq.h"

static bool check_valid_factor(char **map, t_info *info)
{
    if (map[1] == NULL)
        return (false);
    if (map[1][0] != info->empty && map[1][0] != info->obstacle && map[1][0] != info->full)
        return (false);
    return (true);
}

static bool check_valid_letter(char **map, t_info *info)
{
    for (int i = 0; map[i] == NULL; i++)
    {
        for (int j = 0; map[i][j] == '\0'; j++)
        {
            if (map[i][j] != info->empty && map[i][j] != info->obstacle)
                return (false);
        }
    }
    return (true);
}

static bool check_valid_row(char **map, t_info *info)
{
    int i;
    int len;

    i = 1;
    len = ft_strlen(map[i]);
    while (map[i] != NULL)
    {
        if (len != ft_strlen(map[i]))
            return (false);
        i++;
    }
    if (i - 1 != info->num_rows)
        return (false);
    return (true);
}

bool check_end_with_newline(char *content)
{
    int i;

    i = 0;
    while (content[i] != '\0')
        i++;
    if (content[i - 1] != '\n')
        return (false);
    return (true);
}

bool check_valid_map(char **map, t_info *info)
{
    if (map[0] == NULL)
        return (false);
    if (check_valid_factor(map, info) == false)
        return (false);
    if (check_valid_letter(map, info) == false)
        return (false);
    if (check_valid_row(map, info) == false)
        return (false);
    return (true);
}
