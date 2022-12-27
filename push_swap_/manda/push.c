/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:25 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/18 16:35:59 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void    ft_push(t_list **stack_from,t_list **stack_to, char *str )
{
    t_list  *tmp;

    if (!ft_lstsize(* stack_from))
        return ;
    tmp = (* stack_from)->next;
    ft_lstadd_front(stack_to, * stack_from);
    * stack_from = tmp;
    write(1, str, 3);
}