/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:17:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next == last)
			tmp->next = NULL;
		tmp = tmp->next;
	}
	ft_lstadd_front(stack, last);
	if (str)
		write(1, str, 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a, NULL);
	ft_reverse_rotate(stack_b, NULL);
	write(1, "rrr\n", 4);
}
