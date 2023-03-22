/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:39 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 13:38:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			philo;
	pthread_mutex_t		mutex;
	pthread_mutex_t		m_lm;
	int					index;
	int					nbr_meal;
	unsigned long long	last_meal;
}	t_philo;

typedef struct s_vars
{
	t_philo				*philos;
	int					nbr_philo;
	unsigned long long	time_stamp;
	unsigned long long	t_die;
	unsigned long long	t_eat;
	unsigned long long	t_sleep;
	int					nbr_philo_eat;
	int					status;
}	t_vars;

typedef struct s_data
{
	t_vars	*vars;
	int		index;
}	t_data;

unsigned long long	get_time(void);
void				*live(void *vars);
void				*live(void *vars);
unsigned long long	ft_atoi(char *str);
void				*watch(void *vars);
void				philo_loop(t_vars *vars);
void				ft_free_data(t_vars *vars);
int					ft_parser(int ac, char *av[]);
void				ft_unlock_mutexes(void *vars);
void				ft_start_by_eating(t_data *args);
int					ft_is_alive(t_data *data, int i);
void				ft_start_by_sleeping(t_data *args);
void				update_data(t_data *args, int index, int prev);

#endif