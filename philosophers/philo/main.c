/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:29 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/17 12:38:26 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void    ft_update_forks(t_data  *args, int f1_index, int f2_index, int value)
{
    pthread_mutex_lock(&args->vars->mutex);
    args->vars->forks[f1_index].status = value;
    args->vars->forks[f2_index].status = value;
    pthread_mutex_unlock(&args->vars->mutex);
}

int     ft_check_forks_availibility(t_data  *args, int f1_index, int f2_index)
{
    if (args->vars->forks[f1_index].status 
        || args->vars->forks[f2_index].status)
        sleep(args->vars->t_die);
    if (args->vars->forks[f1_index].status 
        || args->vars->forks[f2_index].status)
    {
        printf("philo die !!\n");
        return (-1);
    }
    ft_update_forks(args, f1_index, f2_index, 1);
    return (0);
}

int ft_start_by_eating(t_data *args)
{
    int index;

    index = args->vars->philos[args->index].index;
    while (1)
    {
        if (ft_check_forks_availibility(args, index - 1, index - 2))
            return (-1);
        printf("philo N %d start eating\n", index);
        usleep(args->vars->t_eat);
        ft_update_forks(args, index - 1, index - 2, 0);
        printf("philo N %d start sleaping\n", index);
        usleep(args->vars->t_eat);
        printf("philo N %d start thinking\n", index);
    }
    return (0);
}

int ft_start_by_sleeping(t_data *args)
{
    int index;

    index = args->vars->philos[args->index].index;
    while (1)
    {
        printf("philo N %d start sleeping\n", index);
        usleep(args->vars->t_sleep);
        if (index == 1)
        {
            if (ft_check_forks_availibility(args, 0, args->vars->nbr_philo - 1))
                return (-1);    
        }
        else
        {
            if (ft_check_forks_availibility(args, index - 1, args->vars->nbr_philo - 2))
                return (-1);
        }
        printf("philo N %d start eating\n", index);
        usleep(args->vars->t_eat);
        if (index == 1)
            ft_update_forks(args, 0, args->vars->nbr_philo - 1, 0);
        else
            ft_update_forks(args, index - 1, index - 2, 0);
        printf("philo N %d start thinking\n", index);
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
        vars->current_philo = i;// no need just remove it
        pthread_create(&vars->philos[i].philo, NULL, &live
                , &(t_data){vars, i});
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
    vars.t_die = 500;
    vars.t_eat = 100;
    vars.t_sleep = 300;
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