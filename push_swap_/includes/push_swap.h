/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:42:56 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/28 16:58:22 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../includes/libft.h"

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void    exit_error(void);
int     ft_get_max(t_list *stack);
int     ft_get_min(t_list *stack);
int     ft_isDigit(char *str);
int     ft_inList(t_list *lst, int number);
void    ft_freeArgs(char **arr);
int     ft_lst_insert(t_list **lst, char *arg, char **args);
void    ft_swap(t_list **stack, char *str);
void    ft_ss(t_list **stack_a, t_list **stack_b);
void    ft_push(t_list **stack_from,t_list **stack_to, char *str );
void    ft_rotate(t_list **stack, char *str);
void    ft_rr(t_list **stack_a, t_list **stack_b);
void    ft_reverse_rotate(t_list **stack, char *str);
void    ft_rrr(t_list **stack_a, t_list **stack_b);
int     ft_isorted(t_list *stack_a);
void    ft_push_swap(t_list **stack_a, t_list **stack_b);

# endif