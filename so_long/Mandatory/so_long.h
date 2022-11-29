
#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

// #define FocusIn 9
// #define FocusChangeMask 1L<<21
// #define KeyPress 2
// #define KeyPressMask 1L<<0
// #define DestroyNotify 17
// #define StructureNotifyMask 1L<<17
// #define XK_Escape 53
// #define XK_q 12
// #define XK_Left 123
// #define XK_Up 126
// #define XK_Right 124
// #define XK_Down 125
// #define XK_w 13
// #define XK_s 1
// #define XK_d 2
// #define XK_a 0

typedef struct s_play
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*back_i;
	void	*wall_i;
	void	*ply_i;
	void	*collt_i;
	void	*exit_i;
	char 	**map;
	int		i_h;
	int		i_w;
	int		m_h;
	int		m_w;
	int 	exit;
	int 	collect;
	int 	startp;
	int		x_ply_cord;
	int		y_ply_cord;
	int 	x_exit_cord;
    int 	y_exit_cord;
	int		moves;
	int 	game_over;
}	t_play;

char	**ft_read_map(char *map_path);
int 	valid_map(t_play *play);
void    paly_init(t_play *play);
void	draw_i(t_play *play, void *image, int x, int y);
int		map_draw(t_play *play);
void    start_play(t_play *play);
void    ft_play_vetc(t_play *play, char presse_key, int move);
void    ft_play_horz(t_play *play, char presse_key, int move);
void	free_map(char **map);
int		game_over(t_play *play);
int 	valid_path(t_play *play, char *map_path);

#endif