/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/15 21:27:27 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    *live(void *vars)
{
    t_data  *args;
    
    args = vars;
    if (args->philo.index % 2 == 0)
    {
        while (1)
        {
            pthread_mutex_lock(&args->vars->mutex);
            if (args->philo.index == 1)
            {
                if (args->vars->forks[0].status 
                    || args->vars->forks[args->vars->nbr_philo - 1].status)
                    usleep(args->vars->t_die);
                if (args->vars->forks[0].status 
                    || args->vars->forks[args->vars->nbr_philo - 1].status)
                {
                    printf("philo die !!\n");
                    exit(1);
                }
                args->vars->forks[0].status = 1;
                args->vars->forks[args->vars->nbr_philo - 1].status = 1;
            }
            else
            {
                if (args->vars->forks[args->philo.index - 1].status 
                    || args->vars->forks[args->philo.index - 2].status)
                    usleep(args->vars->t_die);
                if (args->vars->forks[args->philo.index - 1].status 
                    || args->vars->forks[args->philo.index - 2].status)
                {
                    printf("philo die !!\n");
                    exit(1);
                }
                args->vars->forks[args->philo.index - 1].status = 1;
                args->vars->forks[args->philo.index - 2].status = 1;
            }
            pthread_mutex_unlock(&args->vars->mutex);
            printf("philo N %d start eating\n", args->philo.index);
            usleep(args->vars->t_eat);
            pthread_mutex_lock(&args->vars->mutex);
            if (args->philo.index == 1)
            {
                args->vars->forks[0].status = 0;
                args->vars->forks[args->vars->nbr_philo - 1].status = 0;
            }
            else
            {
                args->vars->forks[args->philo.index - 1].status = 0;
                args->vars->forks[args->philo.index - 2].status = 0;
            }
            pthread_mutex_unlock(&args->vars->mutex);
            printf("philo N %d start sleaping\n", args->philo.index);
            usleep(args->vars->t_eat);
            printf("philo N %d start thinking\n", args->philo.index);
        }
    }
    else
    {
        while (1)
        {
        printf("philo N %d start sleeping\n", args->philo.index);
        usleep(args->vars->t_sleep);
        pthread_mutex_lock(&args->vars->mutex);
        if (args->philo.index == 1)
        {
            if (args->vars->forks[0].status 
                || args->vars->forks[args->vars->nbr_philo - 1].status)
                usleep(args->vars->t_die);
            if (args->vars->forks[0].status 
                || args->vars->forks[args->vars->nbr_philo - 1].status)
            {
                printf("philo die !!\n");
                exit(1);
            }
            args->vars->forks[0].status = 1;
            args->vars->forks[args->vars->nbr_philo - 1].status = 1;
        }
        else
        {
            if (args->vars->forks[args->philo.index - 1].status 
                || args->vars->forks[args->philo.index - 2].status)
                usleep(args->vars->t_die);
            if (args->vars->forks[args->philo.index - 1].status 
                || args->vars->forks[args->philo.index - 2].status)
            {
                printf("philo die !!\n");
                exit(1);
            }
            args->vars->forks[args->philo.index - 1].status = 1;
            args->vars->forks[args->philo.index - 2].status = 1;
        }
        pthread_mutex_unlock(&args->vars->mutex);
        printf("philo N %d start eating\n", args->philo.index);
        usleep(args->vars->t_eat);
        pthread_mutex_lock(&args->vars->mutex);
        if (args->philo.index == 1)
        {
            args->vars->forks[0].status = 0;
            args->vars->forks[args->vars->nbr_philo - 1].status = 0;
        }
        else
        {
            args->vars->forks[args->philo.index - 1].status = 0;
            args->vars->forks[args->philo.index - 2].status = 0;
        }
        pthread_mutex_unlock(&args->vars->mutex);
        printf("philo N %d start thinking\n", args->philo.index);
        }
    }
    
    return (NULL);
}

void    ft_philos_init(t_vars *vars)
{
    int i;

    i = -1;
    vars->philos = malloc(sizeof(t_philo) * vars->nbr_philo);
    vars->forks = malloc(sizeof(t_fork) * vars->nbr_philo);
    while (++i < vars->nbr_philo)
    {
        vars->forks[i].status = 0;
        vars->philos[i].index = i + 1;
        vars->philos[i].alive = 1;
        vars->philos[i].activity = 1;
        vars->current_philo = i;
        pthread_create(&vars->philos[i].philo, NULL, &live
                , &(t_data){vars->philos[i], vars});
        usleep(50);
    }
}

void    ft_philos_join(t_vars *vars)
{
    int i;

    i = -1;
    while (++i < vars->nbr_philo)
        pthread_join(vars->philos[i].philo, NULL);
}

void    philo_loop(int nbr_philo)
{
    t_vars  vars;
    
    vars.nbr_philo = nbr_philo;
    vars.t_die = 100;
    vars.t_eat = 100;
    vars.t_sleep = 100;
    ft_philos_init(&vars);
    ft_philos_join(&vars);
}

int main(int ac, char *av[])
{
    (void)ac;
    (void)av;
    
    philo_loop(6);
    return (0);
}