/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:20:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/02/04 23:01:29 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_swap(t_list **stack, char *str)
{
	if (!ft_lstsize(*stack))
		return ;
	(*stack)->content ^= (*stack)->next->content;
	(*stack)->next->content ^= (*stack)->content;
	(*stack)->content ^= (*stack)->next->content;
	if (str)
		write(1, str, 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, NULL);
	ft_swap(stack_b, NULL);
	write(1, "ss\n", 3);
}
