/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:36:18 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 13:44:57 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_mutex_init(pthread_mutex_t	*mutex, pthread_mutex_t	*lm_mutex
	, t_vars *vars, int i)
{
	pthread_mutex_init(&mutex[i], NULL);
	pthread_mutex_init(&lm_mutex[i], NULL);
	vars->philos[i].mutex = mutex[i];
	vars->philos[i].m_lm = lm_mutex[i];
}

void	ft_philos_init(t_vars *vars)
{
	int				i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*lm_mutex;
	t_data			*data;

	i = -1;
	vars->philos = malloc(sizeof(t_philo) * vars->nbr_philo + 1);
	mutex = malloc(sizeof(pthread_mutex_t) * vars->nbr_philo);
	lm_mutex = malloc(sizeof(pthread_mutex_t) * vars->nbr_philo);
	data = malloc(sizeof(t_data));
	data->vars = vars;
	while (++i < vars->nbr_philo)
	{
		vars->philos[i].index = i + 1;
		vars->philos[i].nbr_meal = 0;
		vars->philos[i].last_meal = get_time();
		ft_mutex_init(mutex, lm_mutex, vars, i);
		data->index = i;
		pthread_create(&vars->philos[i].philo, NULL, &live, data);
		usleep(50);
	}
	pthread_create(&vars->philos[i].philo, NULL, &watch, data);
	return (ft_free_data(vars), free(data));
}

void	ft_philos_join(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->nbr_philo)
		pthread_join(vars->philos[i].philo, NULL);
	pthread_join(vars->philos[i].philo, NULL);
}

void	philo_loop(t_vars *vars)
{
	ft_philos_init(vars);
	ft_philos_join(vars);
}
