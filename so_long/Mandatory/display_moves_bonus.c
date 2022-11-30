/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:32:37 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:52:53 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_play *play)
{
	char	*str;

	str = ft_itoa(play->moves);
	mlx_string_put(play->mlx_ptr, play->win_ptr, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(play->mlx_ptr, play->win_ptr, 125, 20, 0xFFFFFF, str);
	free(str);
}
