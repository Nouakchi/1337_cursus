/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:43:49 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 10:45:19 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_ext(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_play	play;

	if (ac == 2)
	{
		play.map = ft_read_map(av[1]);
		if (check_ext(av[1]) && valid_map(&play) && valid_path(&play, av[1]))
		{
			paly_init(&play);
			start_play(&play);
			mlx_loop(play.mlx_ptr);
		}
		else
		{
			if (play.map)
				free_map(play.map);
			ft_printf("Invalid Map\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Invalid args\n");
		exit(1);
	}
	return (0);
}
