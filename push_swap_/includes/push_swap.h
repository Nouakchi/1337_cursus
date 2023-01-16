/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:42:56 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:34:12 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../includes/libft.h"

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data
{
    int first;
    int next;
}   t_data;

void    exit_error(void);
int     ft_is_digit(char *str);
void    ft_free_args(char **arr);
int     ft_get_max(t_list *stack);
int     ft_get_min(t_list *stack);
void    ft_case3(t_list **stack_a);
int     ft_isorted(t_list *stack_a);
void    ft_push_swap(t_list **stack_a);
void    ft_sort_array(int *arr, int len);
int    *ft_arr_fillsorted(t_list *stack);
int     ft_in_list(t_list *lst, int number);
void    ft_swap(t_list **stack, char *str);
t_data  get_max(t_list **stack_b, int *arr);
void    ft_rotate(t_list **stack, char *str);
int     ft_get_index(t_list *stack, int number);
void    ft_rr(t_list **stack_a, t_list **stack_b);
void    ft_ss(t_list **stack_a, t_list **stack_b);
int	    ft_count_mvmnt(t_list *stack, int number);
void    ft_rrr(t_list **stack_a, t_list **stack_b);
void    ft_reverse_rotate(t_list **stack, char *str);
int     ft_lst_insert(t_list **lst, char *arg, char **args);
int     get_half(int *arr, int start, int chunk, int number);
int     ft_search_arr(int *arr, int start, int end, int number);
void    ft_push(t_list **stack_from,t_list **stack_to, char *str );
void    ft_small_stack(t_list **stack_a, t_list **stack_b, int divs);
void	ft_big_stack(t_list **stack_a, t_list **stack_b, int divs, int length);
# endif