#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

int	game_over(t_play *play)
{
    mlx_destroy_image(play->mlx_ptr, play->collt_i);
	mlx_destroy_image(play->mlx_ptr, play->exit_i);
	mlx_destroy_window(play->mlx_ptr, play->win_ptr);
	mlx_destroy_image(play->mlx_ptr, play->back_i);
	mlx_destroy_image(play->mlx_ptr, play->wall_i);
	mlx_destroy_image(play->mlx_ptr, play->ply_i);
	mlx_destroy_image(play->mlx_ptr, play->enemie_i);
	free_map(play->map);
	free(play->mlx_ptr);
	exit(0);
	return (0);
}
