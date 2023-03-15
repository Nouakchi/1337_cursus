/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/15 20:33:58 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    *live(void *vars)
{
    t_data  *args;
    
    args = vars;
    printf("%d\n", args->philo.index);
    // while (1)
    // {
    //     if ()
    // }
    
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