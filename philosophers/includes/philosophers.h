/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:39 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/20 15:35:06 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
    pthread_t   philo;
    pthread_mutex_t mutex;
    int index;
    int nbr_meal;
    int last_meal;
}   t_philo;

typedef struct s_vars
{
    t_philo   *philos;
    int time_stamp;
    int nbr_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int nbr_philo_eat;
    int status;
}   t_vars;

typedef struct s_data
{
    t_vars  *vars;
    int     index;
}   t_data;


#endif