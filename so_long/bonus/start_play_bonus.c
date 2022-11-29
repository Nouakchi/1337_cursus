/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_play_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:50:55 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/29 21:13:28 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_event(int key, t_play *play)
{
	if (key == XK_W || key == XK_UP)
	{
		play->y_ply_cord -= 1;
		ft_play_horz(play, 'w', 1);
	}
	else if (key == XK_S || key == XK_DOWN)
	{
		play->y_ply_cord += 1;
		ft_play_horz(play, 's', -1);
	}
	else if (key == XK_D || key == XK_RIGHT)
	{
		play->x_ply_cord += 1;
		ft_play_vetc(play, 'd', -1);
	}
	else if (key == XK_A || key == XK_LEFT)
	{
		play->x_ply_cord -= 1;
		ft_play_vetc(play, 'a', 1);
	}
}

static int	handle_press(int key, t_play *play)
{
	if (key == XK_ESCAPE || key == XK_Q)
		game_over(play);
	else if (!play->game_over)
	{
		check_event(key, play);
		ft_printf("You moved: %d times\n", play->moves);
	}
	return (0);
}

void	start_play(t_play *play)
{
	mlx_hook(play->win_ptr, KEYPRESS, 0, handle_press, play);
	mlx_hook(play->win_ptr, DESTROYNOTIFY, 0, game_over, play);
	mlx_loop_hook(play->mlx_ptr, sprite_animation, play);
}
