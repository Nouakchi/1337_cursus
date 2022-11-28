#include "so_long_bonus.h"

static void set_p_e_pos(t_play *play)
{
    int i;
    int j;

    i = -1;
    while (play->map[++i] != NULL)
    {
        j = -1;
        while (play->map[i][++j])
        {
            if (play->map[i][j] == 'P')
            {
                play->x_ply_cord = j;
                play->y_ply_cord = i;
            }
            else if (play->map[i][j] == 'E')
            {
                play->x_exit_cord = j;
                play->y_exit_cord = i;
            }
        }
    }
}

static int find_path(int s_y, int s_x, int d_y, int d_x, char **a)
{
    if (s_x == d_x && s_y == d_y)
        return (1);
    else if (a[s_y][s_x] == '1' || a[s_y][s_x] == 'K' )
        return (0);
    a[s_y][s_x] = '1';
    if (find_path(s_y, s_x + 1, d_y, d_x, a)) return (1);
    if (find_path(s_y + 1, s_x, d_y, d_x, a)) return (1);
    if (find_path(s_y - 1, s_x, d_y, d_x, a)) return (1);
    if (find_path(s_y, s_x - 1, d_y, d_x, a)) return (1);
    a[s_y][s_x] = '0';
    return (0);
}

int valid_path(t_play *play, char **map)
{
    set_p_e_pos(play);
    if (find_path(play->y_ply_cord, play->x_ply_cord,
                    play->y_exit_cord, play->x_exit_cord, map))
        return (1);
    return (0);
}