#include "so_long.h"

static void updt_plyr_i(char presse_key, t_play *play)
{
    mlx_destroy_image(play->mlx_ptr, play->ply_i);
	if (presse_key == 'w')
		play->ply_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "textures/PD.xpm", &play->i_w, &play->i_h);
	else if (presse_key == 's')
		play->ply_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "textures/PA.xpm", &play->i_w, &play->i_h);
	else if (presse_key == 'd')
		play->ply_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "textures/PD.xpm", &play->i_w, &play->i_h);
	else if (presse_key == 'a')
		play->ply_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "textures/PA.xpm", &play->i_w, &play->i_h);
}

void    ft_play_vetc(t_play *play, char presse_key, int move)
{
    updt_plyr_i(presse_key, play);
	if (play->map[play->y_ply_cord][play->x_ply_cord] == 'E'
			&& play->collect == 0)
	{
		mlx_clear_window(play->mlx_ptr, play->win_ptr);
		play->map[play->y_ply_cord][play->x_ply_cord + move] = '0';
		play->moves++;
		play->game_over = 1;
		map_draw(play);
	}
	else if (play->map[play->y_ply_cord][play->x_ply_cord] == '1'
			|| play->map[play->y_ply_cord][play->x_ply_cord] == 'E')
		play->x_ply_cord += move;
	else
	{
		mlx_clear_window(play->mlx_ptr, play->win_ptr);
		if (play->map[play->y_ply_cord][play->x_ply_cord] == 'C')
			play->collect -= 1;
		play->map[play->y_ply_cord][play->x_ply_cord] = 'P';
		play->map[play->y_ply_cord][play->x_ply_cord + move] = '0';
		play->moves++;
		map_draw(play);
	}
}

void    ft_play_horz(t_play *play, char presse_key, int move)
{
    updt_plyr_i(presse_key, play);
	if (play->map[play->y_ply_cord][play->x_ply_cord] == 'E'
			&& play->collect == 0)
	{
		mlx_clear_window(play->mlx_ptr, play->win_ptr);
		play->map[play->y_ply_cord + move][play->x_ply_cord] = '0';
		play->moves++;
		play->game_over = 1;
		map_draw(play);
	}
	else if (play->map[play->y_ply_cord][play->x_ply_cord] == '1'
			|| play->map[play->y_ply_cord][play->x_ply_cord] == 'E')
		play->y_ply_cord += move;
	else
	{
		mlx_clear_window(play->mlx_ptr, play->win_ptr);
		if (play->map[play->y_ply_cord][play->x_ply_cord] == 'C')
			play->collect -= 1;
		play->map[play->y_ply_cord][play->x_ply_cord] = 'P';
		play->map[play->y_ply_cord + move][play->x_ply_cord] = '0';
		play->moves++;
		map_draw(play);
	}
}

