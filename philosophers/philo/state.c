/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:11 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 13:29:01 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_alive(t_data *data, int i)
{
	if (get_time() - data->vars->philos[i].last_meal > data->vars->t_die)
	{
		printf("%llu %d died\n" \
			, get_time() - data->vars->time_stamp, i + 1);
		pthread_mutex_unlock(&data->vars->philos[i].m_lm);
		return (0);
	}
	return (1);
}

void	*live(void *vars)
{
	t_data	*args;

	args = vars;
	if (args->vars->philos[args->index].index % 2 != 0)
		ft_start_by_eating(args);
	else
		ft_start_by_sleeping(args);
	return (&args->vars->status);
}

void	update_data(t_data *args, int index, int prev)
{
	pthread_mutex_lock(&args->vars->philos[index - 1].m_lm);
	args->vars->philos[index - 1].last_meal = get_time();
	args->vars->philos[index - 1].nbr_meal++;
	pthread_mutex_unlock(&args->vars->philos[index - 1].m_lm);
	pthread_mutex_unlock(&args->vars->philos[prev].mutex);
	pthread_mutex_unlock(&args->vars->philos[index - 1].mutex);
}
