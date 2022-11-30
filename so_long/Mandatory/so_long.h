/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:27:16 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:30:43 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define XK_ESCAPE 53
# define XK_Q 12
# define XK_LEFT 123
# define XK_UP 126
# define XK_RIGHT 124
# define XK_DOWN 125
# define XK_W 13
# define XK_S 1
# define XK_D 2
# define XK_A 0

typedef struct s_play
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*back_i;
	void	*wall_i;
	void	*ply_i;
	void	*collt_i;
	void	*exit_i;
	char	**map;
	int		i_h;
	int		i_w;
	int		m_h;
	int		m_w;
	int		exit;
	int		collect;
	int		startp;
	int		x_ply_cord;
	int		y_ply_cord;
	int		x_exit_cord;
	int		y_exit_cord;
	int		moves;
	int		game_over;
}	t_play;

typedef struct s_cords
{
	int	s_y;
	int	s_x;
	int	d_y;
	int	d_x;
}	t_cords;

char	**ft_read_map(char *map_path);
int		valid_map(t_play *play);
void	paly_init(t_play *play);
void	draw_i(t_play *play, void *image, int x, int y);
int		map_draw(t_play *play);
void	start_play(t_play *play);
void	ft_play_vetc(t_play *play, char presse_key, int move);
void	ft_play_horz(t_play *play, char presse_key, int move);
void	free_map(char **map);
int		game_over(t_play *play);
int		valid_path(t_play *play, char *map_path);
int		ft_printf(const char *str, ...);
#endif