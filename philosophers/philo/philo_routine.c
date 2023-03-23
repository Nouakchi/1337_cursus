/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/23 14:45:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start2(t_data *args, int index, unsigned long long time_stamp, int prev)
{
	while (args->vars->status != 1)
	{
		pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d has taken a fork\n", get_time() - time_stamp, index);
		pthread_mutex_lock(&args->vars->philos[prev].mutex);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d has taken a fork\n%llu %d is eating\n" \
			, get_time() - time_stamp, index, get_time() - time_stamp, index);
		update_data(args, index, prev);
		usleep(args->vars->t_eat * 1000);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d is sleaping\n", get_time() - time_stamp, index);
		usleep(args->vars->t_sleep * 1000);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d is thinking\n", get_time() - time_stamp, index);
	}
}

void	ft_start_by_eating(t_data *args)
{
	int					index;
	int					prev;
	unsigned long long	time_stamp;

	index = args->vars->philos[args->index].index;
	time_stamp = args->vars->time_stamp;
	prev = index - 2;
	if (index == 1)
		prev = args->vars->nbr_philo - 1;
	start2(args, index, time_stamp, prev);
}

void	start(t_data *args, int index, unsigned long long time_stamp, int prev)
{
	while (args->vars->status != 1)
	{
		if (args->vars->status == 1)
			break ;
		printf("%llu %d is sleeping\n", get_time() - time_stamp, index);
		usleep(args->vars->t_sleep * 1000);
		pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d has taken a fork\n", get_time() - time_stamp, index);
		pthread_mutex_lock(&args->vars->philos[prev].mutex);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d has taken a fork\n%llu %d is eating\n" \
			, get_time() - time_stamp, index, get_time() - time_stamp, index);
		update_data(args, index, prev);
		usleep(args->vars->t_eat * 1000);
		if (args->vars->status == 1)
			break ;
		printf("%llu %d is thinking\n", get_time() - time_stamp, index);
	}
}

void	ft_start_by_sleeping(t_data *args)
{
	int					index;
	int					prev;
	unsigned long long	time_stamp;

	index = args->vars->philos[args->index].index;
	time_stamp = args->vars->time_stamp;
	prev = index - 2;
	if (index == 1)
		prev = args->vars->nbr_philo - 1;
	start(args, index, time_stamp, prev);
}

void	*watch(void *vars)
{
	int					i;
	unsigned long long	last_meal;
	t_data				*data;

	data = vars;
	while (1)
	{
		i = -1;
		data->vars->status = -1;
		usleep(5000);
		while (++i < data->vars->nbr_philo)
		{
			last_meal = data->vars->philos[i].last_meal;
			pthread_mutex_lock(&data->vars->philos[i].m_lm);
			if (!ft_is_alive(data, i))
				return (ft_unlock_mutexes(vars), data->vars->status = 1, NULL);
			if (data->vars->nbr_philo_eat != 0
				&& data->vars->philos[i].nbr_meal < data->vars->nbr_philo_eat)
				data->vars->status = 0;
			pthread_mutex_unlock(&data->vars->philos[i].m_lm);
		}
		if (data->vars->nbr_philo_eat != 0 && data->vars->status == -1)
			break ;
	}
	return (ft_unlock_mutexes(vars), data->vars->status = 1, NULL);
}
