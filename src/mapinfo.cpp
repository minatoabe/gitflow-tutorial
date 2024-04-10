#include "../inc/bsq.hpp"

static void set_info(t_info *info, char *line);
static bool check_valid_rowinfo(char *line, int len);
static bool check_valid_letter_info(t_info *info);

t_info *init_mapinfo(char **map)
{
    t_info *info;
    char *line;
    int len;

    if (!map[0])
        return (NULL);
    line = map[0];
    len = ft_strlen(line);
    if (check_valid_rowinfo(line, len) == false)
        return (NULL);
    info = ft_malloc(sizeof(t_info));
    set_info(info, line);
    if (check_valid_letter_info(info) == false)
    {
        ft_free(info);
        return (NULL);
    }
    return (info);
}

static void set_info(t_info *info, char *line)
{
    int len;
    char *num;

    len = ft_strlen(line);
    num = ft_malloc(sizeof(char) * (len - 3) + 1);
    ft_strlcpy(num, line, len - 2);
    info->num_rows = ft_atoi(num);
    info->empty = line[len - 3];
    info->obstacle = line[len - 2];
    info->full = line[len - 1];
    ft_free(num);
}

static bool check_valid_rowinfo(char *line, int len)
{
    if (len < INFO_MIN)
        return (false);
    for (int i = 0; i < len - 3; i++)
    {
        if (!ft_isdigit(line[i]))
            return (false);
    }
    return (true);
}

static bool check_valid_letter_info(t_info *info)
{
    char obstacle;
    char empty;
    char full;

    obstacle = info->obstacle;
    empty = info->empty;
    full = info->full;
    if (!ft_is_printable(empty) || !ft_is_printable(obstacle) || !ft_is_printable(full))
        return (false);
    if (empty == obstacle || obstacle == full || full == empty)
        return (false);
    return (true);
}
