
#include "so_long_bonus.h"

void	draw_i(t_play *play, void *image, int x, int y)
{
	mlx_put_image_to_window
		(play->mlx_ptr, play->win_ptr, image, x * 64, y * 64 + 64);
}

static void	draw_ply(t_play *play, void *image, int x, int y)
{
	play->x_ply_cord = x;
	play->y_ply_cord = y;
	draw_i(play, image, x, y);
}

static void	draw_ext(t_play *play, int x, int y)
{
	if (play->collect == 0)
	{
		mlx_destroy_image(play->mlx_ptr, play->exit_i);
		play->exit_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "textures/E2.xpm", &play->i_w, &play->i_h);
	}
	draw_i(play, play->exit_i, x, y);
}

int	map_draw(t_play *play)
{
	int	y;
	int	x;

	y = -1;
	while (play->map[++y])
	{
		x = -1;
		while (play->map[y][++x])
		{
			if (play->map[y][x] == '1')
				draw_i(play, play->wall_i, x, y);
			else if (play->map[y][x] == '0')
				draw_i(play, play->back_i, x, y);
			else if (play->map[y][x] == 'P')
				draw_ply(play, play->ply_i, x, y);
			else if (play->map[y][x] == 'C')
				draw_i(play, play->collt_i, x, y);
			else if (play->map[y][x] == 'E')
				draw_ext(play, x, y);
			else if (play->map[y][x] == 'K')
				draw_i(play, play->enemie_i, x, y);
		}
	}
	display_moves(play);
	return (0);
}

void	died(t_play *play)
{
	mlx_destroy_image(play->mlx_ptr, play->ply_i);
	mlx_clear_window(play->mlx_ptr, play->win_ptr);
	play->ply_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/T.xpm", &play->i_w, &play->i_h);
	play->game_over = 1;
	map_draw(play);
}
