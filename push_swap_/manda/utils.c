/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:18:11 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/28 16:58:01 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int ft_isorted(t_list *stack_a)
{
    int last_number;
    
    last_number = stack_a->content;
    stack_a = stack_a->next;
    while (stack_a)
    {
        if (last_number > stack_a->content)
            return (0);
        last_number = stack_a->content;
        stack_a = stack_a->next;
    }
    return (1);
}

int ft_get_max(t_list *stack)
{
    int max;

    if (!stack)
        exit(1);
    max = stack->content;
    while (stack)
    {
        if (max < stack->content)
            max = stack->content;
        stack = stack->next;
    }
    return (max);
}

int ft_get_min(t_list *stack)
{
    int min;

    if (!stack)
        exit(1);
    min = stack->content;
    while (stack)
    {
        if (min > stack->content)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}
