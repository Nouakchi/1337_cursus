/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:39 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/21 11:03:45 by onouakch         ###   ########.fr       */
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
    pthread_mutex_t m_lm;
    int index;
    int nbr_meal;
    unsigned long long last_meal;
}   t_philo;

typedef struct s_vars
{
    t_philo   *philos;
    int nbr_philo;
    unsigned long long time_stamp;
    unsigned long long t_die;
    unsigned long long t_eat;
    unsigned long long t_sleep;
    int nbr_philo_eat;
    int status;
}   t_vars;

typedef struct s_data
{
    t_vars  *vars;
    int     index;
}   t_data;


#endif