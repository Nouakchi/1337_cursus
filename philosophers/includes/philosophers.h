/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:39 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/15 20:32:31 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
    pthread_t   philo;
    int index;
    int activity;
    int alive;
}   t_philo;

typedef struct s_fork
{
    int status;
}   t_fork;

typedef struct s_vars
{
    pthread_mutex_t mutex;
    t_philo   *philos;
    t_fork     *forks;
    int current_philo;
    int nbr_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int nbr_philo_eat;
}   t_vars;

typedef struct s_data
{
    t_philo philo;
    t_vars  *vars;
}   t_data;


#endif