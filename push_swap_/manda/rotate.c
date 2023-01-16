/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:40:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:17:42 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_rotate(t_list **stack, char *str)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	if (str)
		write(1, str, 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, NULL);
	ft_rotate(stack_b, NULL);
	write(1, "rr\n", 3);
}
