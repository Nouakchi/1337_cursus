/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:06:41 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:35 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

static void    ft_sort_array(int *arr, int len)
{
	int i;
	int tmp;

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


static int    *ft_arr_fillsorted(t_list *stack)
{
	int     len;
	int     i;
	int     *ar;
	t_list  *tmp;
	
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

// static int  ft_search_inlst(t_list *stack, int number, int len)
// {
// 	int i;

// 	i = 0;
// 	while (stack)
// 	{
// 		if (number == stack->content)
// 		{
// 			if (i < len / 2)
// 				return (1);
// 			else
// 				break;
// 		}
// 		stack = stack->next;
// 		i++;
// 	}
// 	return (0);
// }

void    ft_case3(t_list **stack_a)
{
	int  start;
	int  middle;
	int  last;

	start = (* stack_a)->content;
	middle = (* stack_a)->next->content;
	last = (* stack_a)->next->next->content;
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

void    ft_case5(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b, "pb\n");
	ft_push(stack_a, stack_b, "pb\n");
	ft_case3(stack_a);
	if ((* stack_b)->content < (* stack_b)->next->content)
		ft_swap(stack_b, "sb\n");
	ft_push(stack_b, stack_a, "pa\n");
	ft_rotate(stack_a, "ra\n");
	ft_push(stack_b, stack_a, "pa\n");
}

int     ft_search_arr(int *arr, int start, int end, int number)
{
	int i;

	i = start - 1;
	while (++i < end)
		if (arr[i] == number)
			return (1);
	return (0);
}

int ft_get_index(t_list *stack, int number)
{
	int index;

	index = 0;
	while (stack)
	{
		if (stack->content == number)
			break;
		index++;
		stack = stack->next;
	}
	return (index);
}

int	ft_count_mvmnt(t_list *stack, int number)
{
	int index;
	int len;

	index = ft_get_index(stack, number);
	len = ft_lstsize(stack);
	if (len == 1 || index < len / 2)
		return (index);
	return (((len - 1) - index) + 1);
}
	
void    ft_check_push(t_list **stack_a, t_list **stack_b, int h_fst, int h_scd)
{
	int fst_mvmnt;
	int scd_mvmnt;
	t_list	*tmp;
	int	index;
	
	tmp = * stack_b;
	fst_mvmnt = ft_count_mvmnt(* stack_a, h_fst);
	scd_mvmnt = ft_count_mvmnt(* stack_a, h_scd);
	if (fst_mvmnt < scd_mvmnt)
	{
		if (ft_get_index(* stack_a, h_fst) < ft_lstsize(* stack_a) / 2)
			while (fst_mvmnt-- > 0)
				ft_rotate(stack_a, "ra\n");
		else
			while (fst_mvmnt-- > 0)
				ft_reverse_rotate(stack_a, "rra\n");
	}
	else
	{
		if (ft_get_index(* stack_a, h_scd) < ft_lstsize(* stack_a) / 2)
			while (scd_mvmnt-- > 0)
				ft_rotate(stack_a, "ra\n");
		else
			while (scd_mvmnt-- > 0)
				ft_reverse_rotate(stack_a, "rra\n");
	}
	if (*stack_b && ((* stack_a)->content > ft_get_max(* stack_b) || 
		(* stack_a)->content < ft_get_min(* stack_b)))
	{
		index = ft_count_mvmnt(* stack_b, ft_get_min(* stack_b));
		if (ft_get_index(* stack_b, ft_get_min(* stack_b)) < ft_lstsize(* stack_b) / 2)
			while (index-- > 0)
				ft_rotate(stack_b, "ra\n");
		else
			while (index-- > 0)
				ft_reverse_rotate(stack_b, "rra\n");
	}
	if (*stack_b && ((* stack_a)->content < ft_get_max(* stack_b) && 
		(* stack_a)->content > ft_get_min(* stack_b)))
	{
		int number = (* stack_a)->content;
		int max = ft_get_min(* stack_b);
		tmp = * stack_b;
		while (tmp)
		{
			if (tmp->content < number && max < tmp->content)
				max = tmp->content;
			tmp = tmp->next;
		}
		index = ft_count_mvmnt(* stack_b, max);
		if (ft_get_index(* stack_b, max) < ft_lstsize(* stack_b) / 2)
			while (index-- >= 0)
				ft_rotate(stack_b, "ra\n");
		else
			while (index-- > 1)
				ft_reverse_rotate(stack_b, "rra\n");
	}
	ft_push(stack_a, stack_b, "pa\n");
}

void    ft_case100(t_list **stack_a, t_list **stack_b, int start, int chunk, int *arr)
{
	int hold_first;
	int hold_second;
	t_list  *tmp;

	tmp = (* stack_a);
	while (tmp)
	{
		if (ft_search_arr(arr, start, chunk, tmp->content))
		{
			hold_first = tmp->content;
			break;
		}
		tmp = tmp->next;
	}
	tmp = (* stack_a);
	while (tmp)
	{
		if (ft_search_arr(arr, start, chunk, tmp->content))
			hold_second = tmp->content;
		tmp = tmp->next;
	}
	ft_check_push(stack_a, stack_b, hold_first, hold_second);
}

void    ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int chunks;
	int times;
	int start;
	int len;
	int *arr;
	
	if (ft_lstsize(* stack_a) == 3)
		ft_case3(stack_a);
	else if (ft_lstsize(* stack_a) == 5)
		ft_case5(stack_a, stack_b);
	else if (ft_lstsize(* stack_a) <= 100)
	{
		times = 5;
		chunks = 0;
		start = 0;
		len = ft_lstsize(* stack_a) / 5;
		arr = ft_arr_fillsorted(* stack_a);
		while (times--)
		{
			chunks += len;
			int x = 20;
			while (x-- > 0)
				ft_case100(stack_a, stack_b, start, chunks, arr);
			start += len;
		}
		int index = ft_count_mvmnt(* stack_b, ft_get_max(* stack_b));
		if (ft_get_index(* stack_b, ft_get_max(* stack_b)) < ft_lstsize(* stack_b) / 2)
			while (index-- > 0)
				ft_rotate(stack_b, "ra\n");
		else
			while (index-- > 0)
				ft_reverse_rotate(stack_b, "rra\n");
		
		while (ft_lstsize(* stack_b))
		{
			ft_push(stack_b, stack_a, "pb\n");
			ft_reverse_rotate(stack_b, "rra\n");
		}
	}
}


// int main()
// {
//     t_list *t = ft_lstnew(5);
//     t->next = ft_lstnew(3);
//     t->next->next = ft_lstnew(-1);
//     t->next->next->next = ft_lstnew(9);
//     int *ar = ft_arr_fillsorted(t);
//     int i = -1;
//     while (++i < 4)
//         printf("%d\n", ar[i]);
	
// }

