/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:07:40 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:38:27 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_data	get_max(t_list **stack_b, int *arr)
{
	int		i;
	t_data	data;

	data.next = ft_get_max(*stack_b);
	i = 0;
	while (arr[i] != data.next)
		i++;
	data.first = arr[i - 1];
	return (data);
}

void	ft_push_top(t_list **stack, int number, char *str1, char *str2)
{
	int	mouvment;

	mouvment = ft_count_mvmnt(*stack, number);
	if (ft_get_index(*stack, number) < ft_lstsize(*stack) / 2)
		while (mouvment-- > 0)
			ft_rotate(stack, str1);
	else
		while (mouvment-- > 0)
			ft_reverse_rotate(stack, str2);
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b, t_data data, int *arr)
{
	while (!ft_search_arr(arr, data.first, data.next, (*stack_a)->content))
		ft_rotate(stack_a, "ra\n");
	ft_push(stack_a, stack_b, "pb\n");
	if (!get_half(arr, data.first, data.next, (*stack_b)->content))
		ft_rotate(stack_b, "rb\n");
}

void	fill_stack_a(t_list **stack_a, t_list **stack_b, int *arr)
{
	int		fst_mvmnt;
	int		scd_mvmnt;
	t_data	data;

	data = get_max(stack_b, arr);
	fst_mvmnt = ft_count_mvmnt(*stack_b, data.first);
	scd_mvmnt = ft_count_mvmnt(*stack_b, data.next);
	if (fst_mvmnt < scd_mvmnt)
	{
		ft_push_top(stack_b, data.first, "rb\n", "rrb\n");
		ft_push(stack_b, stack_a, "pa\n");
		ft_push_top(stack_b, data.next, "rb\n", "rrb\n");
		ft_push(stack_b, stack_a, "pa\n");
		ft_swap(stack_a, "sa\n");
	}
	else
	{
		ft_push_top(stack_b, data.next, "rb\n", "rrb\n");
		ft_push(stack_b, stack_a, "pa\n");
	}
}

void	ft_big_stack(t_list **stack_a, t_list **stack_b, int divs, int length)
{
	int	*arr;
	int	times;
	int	chunks;
	int	start;
	int	chunk_len;

	chunks = 0;
	start = 0;
	times = divs;
	arr = ft_arr_fillsorted(*stack_a);
	while (times--)
	{
		chunks += length / divs;
		chunk_len = length / divs;
		while (chunk_len-- > 0)
			fill_stack_b(stack_a, stack_b, (t_data){start, chunks}, arr);
		start += length / divs;
	}
	chunk_len = length - divs * (length / divs);
	if (divs * (length / divs) != length)
		while (chunk_len-- > 0)
			fill_stack_b(stack_a, stack_b, (t_data){start, length}, arr);
	while (*stack_b)
		fill_stack_a(stack_a, stack_b, arr);
}
