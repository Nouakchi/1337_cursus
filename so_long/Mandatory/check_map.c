
#include "so_long.h"

static int check_rect(char **map)
{
    int i;

    i = 0;
    if (!map)
        return (0);
    while (map[++i] != NULL)
        if (ft_strlen(map[i]) != ft_strlen(map[0]))
            return (0);
    return (1);
}

static int wall_surrounded(char **map)
{
    int map_len;
    int i;

    map_len = -1;
    while (map[++map_len] != NULL);
    i = -1;
    while (map[0][++i] && map[map_len - 1][i])
        if (map[0][i] != '1' || map[map_len - 1][i] != '1')
            return (0);
    i = 0;
    map_len = ft_strlen(map[0]);
    while (map[++i] != NULL)
        if (map[i][0] != '1' || map[i][map_len - 1] != '1')
            return (0);
    return (1);
}

static int is_valid(char c)
{
    if (c != 'P' && c != 'E' && c != 'C'
				&& c != '0' && c != '1')
				return (0);
    return (1);
}

static int check_wepec(t_play *play)
{
    int i;
    int j;

    i = -1;
    play->collect = 0;
    play->exit = 0;
    play->startp = 0;
    while (play->map[++i] != NULL)
    {
        j = -1;
        while (play->map[i][++j])
        {
            if (!is_valid(play->map[i][j]))
                return (0);
            if (play->map[i][j] == 'P')
                play->startp++;
            else if (play->map[i][j] == 'E')
                play->exit++;
            else if (play->map[i][j] == 'C')
                play->collect++;
        }
    }
    if (play->exit != 1 || play->collect == 0 || play->startp != 1)
        return (0);
    return (1);
}

int valid_map(t_play *play)
{
    if (!check_rect(play->map) || !wall_surrounded(play->map) || !check_wepec(play))
        return (0);
    return (1);
}