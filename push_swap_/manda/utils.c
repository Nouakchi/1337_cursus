/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:18:11 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/21 17:49:32 by onouakch         ###   ########.fr       */
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


