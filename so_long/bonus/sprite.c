#include "so_long_bonus.h"

int	sprite_animation(t_play *play)
{
	if (play->loop < 10000)
	{
		play->loop++;
		return (0);
	}
	play->loop = 0;
	mlx_destroy_image(play->mlx_ptr, play->enemie_i);
	if (play->enemie_p == 1)
		play->enemie_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "resources/images/EN1.xpm", &play->i_w, &play->i_h);
	else if (play->enemie_p == 2)
	{
		play->enemie_i = mlx_xpm_file_to_image
			(play->mlx_ptr, "resources/images/EN2.xpm", &play->i_w, &play->i_h);
		play->enemie_p = 0;
	}
	map_draw(play);
	play->enemie_p++;
	return (0);
}