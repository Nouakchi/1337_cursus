/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:10 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 16:02:55 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long long	ft_atoi(char *str)
{
	unsigned long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res);
}

int	ft_parser(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (-1);
	}
	return (0);
}

void	ft_free_data(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->nbr_philo)
	{
		pthread_mutex_destroy(&vars->philos[i].mutex);
		pthread_mutex_destroy(&vars->philos[i].m_lm);
	}
	free(vars->mutex);
	free(vars->lm_mutex);
	free(vars->philos);
}

unsigned long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_unlock_mutexes(void *vars)
{
	int		i;
	t_data	*data;

	data = vars;
	i = -1;
	while (++i < data->vars->nbr_philo)
		pthread_mutex_unlock(&data->vars->philos[i].mutex);
}
