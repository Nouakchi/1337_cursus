/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:54:12 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 08:39:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_p_e_pos(t_play *play)
{
	int	i;
	int	j;

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

static int	find_path(t_cords cords, char **a)
{
	int	s_x;
	int	s_y;
	int	d_x;
	int	d_y;

	s_x = cords.s_x;
	s_y = cords.s_y;
	d_x = cords.d_x;
	d_y = cords.d_y;
	if (s_x == d_x && s_y == d_y)
		return (1);
	else if (a[s_y][s_x] == '1' || a[s_y][s_x] == 'K')
		return (0);
	a[s_y][s_x] = '1';
	if (find_path((t_cords){s_y, s_x + 1, d_y, d_x}, a))
		return (1);
	if (find_path((t_cords){s_y + 1, s_x, d_y, d_x}, a))
		return (1);
	if (find_path((t_cords){s_y - 1, s_x, d_y, d_x}, a))
		return (1);
	if (find_path((t_cords){s_y, s_x - 1, d_y, d_x}, a))
		return (1);
	a[s_y][s_x] = '0';
	return (0);
}

int	valid_path(t_play *play, char *map_path)
{
	char	**map;

	map = ft_read_map(map_path);
	set_p_e_pos(play);
	if (find_path((t_cords){play->y_ply_cord, play->x_ply_cord,
			play->y_exit_cord, play->x_exit_cord}, map))
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}
