/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:45:17 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:38:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_sort_array(int *arr, int len)
{
	int	i;
	int	tmp;

	while (len--)
	{
		i = -1;
		while (++i < len)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}

int	*ft_arr_fillsorted(t_list *stack)
{
	int		len;
	int		i;
	int		*ar;
	t_list	*tmp;

	len = ft_lstsize(stack);
	ar = (int *)malloc(len * sizeof(int));
	if (!ar)
		return (NULL);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		ar[i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_sort_array(ar, len);
	return (ar);
}

void	ft_push_swap(t_list **stack_a)
{
	int		length;
	t_list	*stack_b;

	stack_b = NULL;
	length = ft_lstsize(*stack_a);
	if (length == 3)
		ft_case3(stack_a);
	else if (length <= 5)
		ft_small_stack(stack_a, &stack_b, length);
	else if (length <= 200)
		ft_big_stack(stack_a, &stack_b, 5, length);
	else
		ft_big_stack(stack_a, &stack_b, 10, length);
}
