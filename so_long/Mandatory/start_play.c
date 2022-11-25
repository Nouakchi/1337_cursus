#include "so_long.h"

static void check_event(int key, t_play *play)
{
    if (key == XK_w || key == XK_Up)
	{
		play->y_ply_cord -= 1;
		ft_play_horz(play, 'w', 1);
	}
	else if (key == XK_s || key == XK_Down)
	{
		play->y_ply_cord += 1;
		ft_play_horz(play, 's', -1);
	}
	else if (key == XK_d || key == XK_Right)
	{
		play->x_ply_cord += 1;
		ft_play_vetc(play, 'd', -1);
	}
	else if (key == XK_a || key == XK_Left)
	{
		play->x_ply_cord -= 1;
		ft_play_vetc(play, 'a', 1);
	}
}

static  int handle_press(int key, t_play *play)
{
    if (key == XK_Escape || key == XK_q)
        game_over(play);
    else if (!play->game_over)
    {
        check_event(key, play);
        printf("You moved: %d times\n", play->moves);
    }
	return (0);
}

void    start_play(t_play *play)
{
	mlx_hook(play->win_ptr, FocusIn, FocusChangeMask, map_draw, play);
    mlx_hook(play->win_ptr, KeyPress, KeyPressMask, handle_press, play);
	mlx_hook(play->win_ptr, DestroyNotify, StructureNotifyMask, game_over, play);
}