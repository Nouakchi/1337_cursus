/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/22 11:29:09 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long long    get_time(void)
{
    struct timeval now;
    
    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void ft_start_by_eating(t_data *args)
{
    int index;
    int prev;
    unsigned long long time_stamp;
    
    index = args->vars->philos[args->index].index;
    time_stamp = args->vars->time_stamp;
    prev = index - 2;
    if (index == 1)
        prev = args->vars->nbr_philo - 1;
    while (args->vars->status != 1)
    {
        pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d has taken a fork\n", get_time() - time_stamp, index);
        pthread_mutex_lock(&args->vars->philos[prev].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d has taken a fork\n%llu %d is eating\n"
            , get_time() - time_stamp, index, get_time() - time_stamp, index);
        usleep(args->vars->t_eat * 1000);
        pthread_mutex_lock(&args->vars->philos[index - 1].m_lm);
        args->vars->philos[index - 1].last_meal = get_time();
        args->vars->philos[index - 1].nbr_meal++;
        pthread_mutex_unlock(&args->vars->philos[index - 1].m_lm);
        pthread_mutex_unlock(&args->vars->philos[prev].mutex);
        pthread_mutex_unlock(&args->vars->philos[index - 1].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d is sleaping\n", get_time() - time_stamp, index);
        usleep(args->vars->t_eat * 1000);
        if (args->vars->status == 1)
            break;
        printf("%llu %d is thinking\n", get_time() - time_stamp, index);
    }
}

void ft_start_by_sleeping(t_data *args)
{
    int index;
    int prev;
    unsigned long long time_stamp;
    
    index = args->vars->philos[args->index].index;
    time_stamp = args->vars->time_stamp;
    prev = index - 2;
    if (index == 1)
        prev = args->vars->nbr_philo - 1;
    while (args->vars->status != 1)
    {
        if (args->vars->status == 1)
            break;
        printf("%llu %d is sleeping\n", get_time() - time_stamp, index);
        usleep(args->vars->t_sleep * 1000);
        pthread_mutex_lock(&args->vars->philos[index - 1].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d has taken a fork\n", get_time() - time_stamp, index);
        pthread_mutex_lock(&args->vars->philos[prev].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d has taken a fork\n%llu %d is eating\n"
            , get_time() - time_stamp, index, get_time() - time_stamp, index);
        usleep(args->vars->t_eat * 1000);
        pthread_mutex_lock(&args->vars->philos[index - 1].m_lm);
        args->vars->philos[index - 1].last_meal = get_time();
        args->vars->philos[index - 1].nbr_meal++;
        pthread_mutex_unlock(&args->vars->philos[index - 1].m_lm);
        pthread_mutex_unlock(&args->vars->philos[prev].mutex);
        pthread_mutex_unlock(&args->vars->philos[index - 1].mutex);
        if (args->vars->status == 1)
            break;
        printf("%llu %d is thinking\n", get_time() - time_stamp, index);
    }
}

void    *live(void *vars)
{
    t_data  *args;
    
    args = vars;
    if (args->vars->philos[args->index].index % 2 != 0)
        ft_start_by_eating(args);
    else
        ft_start_by_sleeping(args);
    return (&args->vars->status);
}

void    ft_unlock_mutexes(void  *vars)
{
    int i;
    t_data  *data;
    
    data = vars;
    i = -1;
    while (++i < data->vars->nbr_philo)
        pthread_mutex_unlock(&data->vars->philos[i].mutex);
}

void    *watch(void *vars)
{
    int i;
    unsigned long long last_meal;
    t_data  *data;
    
    data = vars;
    while (1)
    {
        i = -1;
        data->vars->status = -1;
        while(++i < data->vars->nbr_philo)
        {
            last_meal = data->vars->philos[i].last_meal;
            pthread_mutex_lock(&data->vars->philos[i].m_lm);
            if (get_time() - data->vars->philos[i].last_meal > data->vars->t_die)
            {
                printf("%llu %d died\n"
                    , get_time() - data->vars->time_stamp, i + 1);
                pthread_mutex_unlock(&data->vars->philos[i].m_lm);
                return (ft_unlock_mutexes(vars), data->vars->status = 1, NULL);
            }
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

void    ft_free_data(t_vars *vars)
{
    int i;

    i = -1;
    while (++i < vars->nbr_philo)
    {
        pthread_mutex_destroy(&vars->philos[i].mutex);
        pthread_mutex_destroy(&vars->philos[i].m_lm);
    }
    free(vars->philos);
}

void    ft_philos_init(t_vars *vars)
{
    int i;
    pthread_mutex_t *mutex;
    pthread_mutex_t *lm_mutex;
    t_data  *data;

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
        pthread_mutex_init(&mutex[i], NULL);
        pthread_mutex_init(&lm_mutex[i], NULL);
        vars->philos[i].mutex = mutex[i];
        vars->philos[i].m_lm = lm_mutex[i];
        data->index = i;
        pthread_create(&vars->philos[i].philo, NULL, &live, data);
        usleep(50);
    }
    pthread_create(&vars->philos[i].philo, NULL, &watch, data);
    return (ft_free_data(vars), free(data));
}

void    ft_philos_join(t_vars *vars)
{
    int i;

    i = -1;
    while (++i < vars->nbr_philo)
        pthread_join(vars->philos[i].philo, NULL);
    pthread_join(vars->philos[i].philo, NULL);
}

void    philo_loop(t_vars *vars)
{
    ft_philos_init(vars);
    ft_philos_join(vars);
}


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

void    ft_init(t_vars *vars, char *av[])
{
    vars->nbr_philo = ft_atoi(av[1]);
    vars->time_stamp = get_time();
    vars->t_die = ft_atoi(av[2]);
    vars->t_eat = ft_atoi(av[3]);
    vars->t_sleep = ft_atoi(av[4]);
}

int     ft_parser(int ac, char *av[])
{
    int i;
    int j;

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

void    check()
{
    system("leaks philo");
}

int main(int ac, char *av[])
{
    t_vars  vars;

    if (ac < 5 || ac > 6 || ft_parser(ac, av))
        return (0);
    atexit(check);
    ft_init(&vars, av);
    vars.nbr_philo_eat = 0;
    if (ac == 6)
        vars.nbr_philo_eat = ft_atoi(av[5]);
    philo_loop(&vars);
    return (0);
}