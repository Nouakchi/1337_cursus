#include "so_long_bonus.h"

static void	img_init(t_play *play)
{
	play->back_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/0.xpm", &play->i_w, &play->i_h);
	play->wall_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/1.xpm", &play->i_w, &play->i_h);
	play->ply_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/PD.xpm", &play->i_w, &play->i_h);
	play->collt_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/C.xpm", &play->i_w, &play->i_h);
	play->exit_i = mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/E1.xpm", &play->i_w, &play->i_h);
	play->enemie_i= mlx_xpm_file_to_image
		(play->mlx_ptr, "textures/EN1.xpm", &play->i_w, &play->i_h);
}

static void	set_win_size(t_play *play)
{
	int	i;

	play->m_w = ft_strlen(play->map[0]) * 64;
	i = 0;
	while (play->map[i] != NULL)
		i++;
	play->m_h = i * 64 + 64;
}

void    paly_init(t_play *play)
{
    play->mlx_ptr = mlx_init();
    set_win_size(play);
    play->win_ptr = mlx_new_window(play->mlx_ptr, play->m_w, play->m_h, "so_long");
    play->game_over = 0;
    play->moves = 0;
	play->enemie_p = 1;
	play->loop = 0;
    img_init(play);
    map_draw(play);
}