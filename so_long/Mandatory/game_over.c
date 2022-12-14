/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:39:46 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:52:53 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_image(play->mlx_ptr, play->back_i);
	mlx_destroy_image(play->mlx_ptr, play->wall_i);
	mlx_destroy_image(play->mlx_ptr, play->ply_i);
	mlx_destroy_image(play->mlx_ptr, play->enemie_i);
	mlx_clear_window(play->mlx_ptr, play->win_ptr);
	mlx_destroy_window(play->mlx_ptr, play->win_ptr);
	free_map(play->map);
	exit(0);
	return (0);
}
