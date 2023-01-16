/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:00 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:38 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_search_arr(int *arr, int start, int end, int number)
{
	int	i;

	i = start - 1;
	while (++i < end)
		if (arr[i] == number)
			return (1);
	return (0);
}

int	ft_count_mvmnt(t_list *stack, int number)
{
	int	index;
	int	len;

	index = ft_get_index(stack, number);
	len = ft_lstsize(stack);
	if (len == 1 || index < len / 2)
		return (index);
	return (((len - 1) - index) + 1);
}

void	ft_case3(t_list **stack_a)
{
	int	start;
	int	middle;
	int	last;

	start = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if (start < last && start > middle && last > middle)
		ft_swap(stack_a, "sa\n");
	else if (start > last && start > middle && last < middle)
	{
		ft_swap(stack_a, "sa\n");
		ft_reverse_rotate(stack_a, "rra\n");
	}
	else if (start > last && start > middle && last > middle)
		ft_rotate(stack_a, "ra\n");
	else if (start < last && start < middle && last < middle)
	{
		ft_swap(stack_a, "sa\n");
		ft_rotate(stack_a, "ra\n");
	}
	else if (start > last && start < middle && last < middle)
		ft_reverse_rotate(stack_a, "rra\n");
}

void	ft_case4(t_list **stack_a, t_list **stack_b)
{
	int	small_mvmn;

	small_mvmn = ft_count_mvmnt(*stack_a, ft_get_min(*stack_a));
	if (ft_get_index(*stack_a, ft_get_min(*stack_a)) < ft_lstsize(*stack_a) / 2)
		while (small_mvmn-- > 0)
			ft_rotate(stack_a, "ra\n");
	else
		while (small_mvmn-- > 0)
			ft_reverse_rotate(stack_a, "rra\n");
	ft_push(stack_a, stack_b, "pb\n");
	ft_case3(stack_a);
	ft_push(stack_b, stack_a, "pa\n");
}

void	ft_small_stack(t_list **stack_a, t_list **stack_b, int divs)
{
	int	small_mvmn;
	int	times;

	times = divs - 3;
	while (times-- > 0)
	{
		small_mvmn = ft_count_mvmnt(*stack_a, ft_get_min(*stack_a));
		if (ft_get_index(*stack_a, ft_get_min(*stack_a))
			< ft_lstsize(*stack_a) / 2)
			while (small_mvmn-- > 0)
				ft_rotate(stack_a, "ra\n");
		else
			while (small_mvmn-- > 0)
				ft_reverse_rotate(stack_a, "rra\n");
		ft_push(stack_a, stack_b, "pb\n");
	}
	ft_case3(stack_a);
	ft_push(stack_b, stack_a, "pa\n");
	ft_push(stack_b, stack_a, "pa\n");
}
