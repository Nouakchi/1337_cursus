/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:00:10 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/29 19:14:36 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void ft_display(int number)
{
    printf("%d\n", number);
}

void ff()
{
    system("leaks push_swap");
}

void    exit_error()
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}



int main(int ac, char **av)
{
    int     av_len;
    int     args_len;
    t_list  *stack_a;
    t_list  *stack_b;
    char    **args;
    
    //atexit(ff);
    if (ac <= 1)
        return (0);
    av_len = 0;
    while (++av_len < ac)
    {
        if (ft_strchr(av[av_len], ' '))
        {
            args = ft_split(av[av_len], ' ');
            args_len = -1;
            while (args[++args_len] != NULL)
                if (!ft_lst_insert(&stack_a, args[args_len], args))
                    return (exit_error(), 0);
            ft_freeArgs(args);
        }
        else
            if (!ft_lst_insert(&stack_a, av[av_len], NULL))
                    return (exit_error(), 0);
    }
    ft_push_swap(&stack_a, &stack_b);
    // ft_lstclear(&stack_a, ft_display);
    // printf("------------\n");
    ft_lstclear(&stack_b, ft_display);
    return (0);
}