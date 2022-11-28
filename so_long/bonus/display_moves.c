#include "so_long_bonus.h"

void	display_moves(t_play *play)
{
	char	*str;

	str = ft_itoa(play->moves);
	mlx_string_put(play->mlx_ptr, play->win_ptr, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(play->mlx_ptr, play->win_ptr, 125, 20, 0xFFFFFF, str);
	free(str);
}