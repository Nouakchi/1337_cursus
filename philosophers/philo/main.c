/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 13:44:43 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check(void)
{
	system("leaks philo");
}

void	ft_init(t_vars *vars, char *av[])
{
	vars->nbr_philo = ft_atoi(av[1]);
	vars->time_stamp = get_time();
	vars->t_die = ft_atoi(av[2]);
	vars->t_eat = ft_atoi(av[3]);
	vars->t_sleep = ft_atoi(av[4]);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac < 5 || ac > 6 || ft_parser(ac, av))
		return (0);
	ft_init(&vars, av);
	vars.nbr_philo_eat = 0;
	if (ac == 6)
		vars.nbr_philo_eat = ft_atoi(av[5]);
	philo_loop(&vars);
	return (0);
}
