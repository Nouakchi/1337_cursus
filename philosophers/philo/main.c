/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/20 15:40:49 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned int    get_time(void)
{
    struct timeval now;
    
    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int ft_start_by_eating(t_data *args)
{
    int index;
    int prev;
    int time_stamp;
    
    index = args->vars->philos[args->index].index;
    time_stamp = args->vars->time_stamp;
    prev = index - 2;
    if (index == 1)
        prev = args->vars->nbr_philo - 1;
    while (1)
    {
        pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
        pthread_mutex_lock(&args->vars->philos[prev].mutex);
        args->vars->philos[index - 1].last_meal = (int)get_time() - time_stamp;
        printf("%d %d has taken a fork\n", get_time() - time_stamp, index);
        printf("%d %d is eating\n", get_time() - time_stamp, index);
        usleep(args->vars->t_eat);
        args->vars->philos[index - 1].nbr_meal++;
        pthread_mutex_unlock(&args->vars->philos[prev].mutex);
        pthread_mutex_unlock(&args->vars->philos[index - 1].mutex);
        printf("%d %d is sleaping\n", get_time() - time_stamp, index);
        usleep(args->vars->t_eat);
        printf("%d %d is thinking\n", get_time() - time_stamp, index);
    }
    return (0);
}

int ft_start_by_sleeping(t_data *args)
{
    int index;
    int prev;
    int time_stamp;
    
    index = args->vars->philos[args->index].index;
    time_stamp = args->vars->time_stamp;
    prev = index - 2;
    if (index == 1)
        prev = args->vars->nbr_philo - 1;
    while (1)
    {
        printf("%d %d is sleeping\n", (int)get_time() - time_stamp, index);
        usleep(args->vars->t_sleep);
        pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
        pthread_mutex_lock(&args->vars->philos[prev].mutex);
        args->vars->philos[index - 1].last_meal = get_time() - time_stamp;
        printf("%d %d has taken a fork\n", get_time() - time_stamp, index);
        printf("%d %d is eating\n", get_time() - time_stamp, index);
        usleep(args->vars->t_eat);
        args->vars->philos[index - 1].nbr_meal++;
        pthread_mutex_unlock(&args->vars->philos[prev].mutex);
        pthread_mutex_unlock(&args->vars->philos[index - 1].mutex);
        printf("%d %d is thinking\n", get_time() - time_stamp, index);
    }
    return (0);
}

void    *live(void *vars)
{
    t_data  *args;
    
    args = vars;
    if (args->vars->philos[args->index].index % 2 == 0)
        ft_start_by_eating(args);
    else
        ft_start_by_sleeping(args);
    return (NULL);
}

// void    *watch(void *vars)
// {
//     int i;
//     t_data  *data;
    
//     data = vars;
//     while (1)
//     {
//         i = -1;
//         data->vars->status = 1;
//         while(++i < data->vars->nbr_philo)
//         {
//             if ((int)get_time() - data->vars->time_stamp - 
//                 data->vars->philos[i].last_meal > data->vars->t_die)
//             {
//                 printf("%d %d died\n"
//                     , get_time() - data->vars->time_stamp, i + 1);
//                 data->vars->status = 0;
//                 break;
//             }
//             if (data->vars->philos[i].nbr_meal < data->vars->nbr_philo_eat)
//             {
//                 data->vars->status = 0;
//                 break ;
//             }
//         }
//         if (data->vars->status)
//             break ;
//     }
//     return (&data->vars->status);
// }

void    *watch(void *vars)
{
    int i;
    t_data  *data;
    
    data = vars;
    while (1)
    {
        i = -1;
        data->vars->status = 1;
        while(++i < data->vars->nbr_philo)
        {
            if ((int)get_time() - data->vars->time_stamp - 
                data->vars->philos[i].last_meal > data->vars->t_die)
            {
                printf("%d %d died\n"
                    , get_time() - data->vars->time_stamp, i + 1);
                data->vars->status = 0;
                break;
            }
            if (data->vars->philos[i].nbr_meal < data->vars->nbr_philo_eat)
            {
                data->vars->status = 0;
                break ;
            }
        }
        if (data->vars->status)
            break ;
    }
    return (&data->vars->status);
}

void    ft_philos_init(t_vars *vars)
{
    int i;
    pthread_mutex_t *mutex;
    t_data  *data;

    i = -1;
    vars->philos = malloc(sizeof(t_philo) * vars->nbr_philo + 1);
    mutex = malloc(sizeof(pthread_mutex_t) * vars->nbr_philo);
    data = malloc(sizeof(t_data));
    data->vars = vars;
    while (++i < vars->nbr_philo)
    {
        vars->philos[i].index = i + 1;
        vars->philos[i].nbr_meal = 0;
        vars->philos[i].last_meal = 0;
        pthread_mutex_init(&mutex[i], NULL);
        vars->philos[i].mutex = mutex[i];
        data->index = i;
        pthread_create(&vars->philos[i].philo, NULL, &live, data);
        usleep(50);
    }
    pthread_create(&vars->philos[i].philo, NULL, &watch, data);
}

void    ft_philos_join(t_vars *vars)
{
    int i;

    i = -1;
    while (++i < vars->nbr_philo)
        pthread_join(vars->philos[i].philo, NULL);
    pthread_join(vars->philos[i].philo, (void**) &vars->status);
    if (vars->status)
        printf("ok\n");
    else
        printf("non ok\n");
}

void    philo_loop(int nbr_philo)
{
    t_vars  vars;
    vars.nbr_philo = nbr_philo;
    vars.time_stamp = get_time();
    vars.t_die = 310;
    vars.t_eat = 200;
    vars.t_sleep = 100;
    vars.nbr_philo_eat = 7;
    ft_philos_init(&vars);
    ft_philos_join(&vars);
}



int main(int ac, char *av[])
{
    (void)ac;
    (void)av;
    philo_loop(4);
    return (0);
}