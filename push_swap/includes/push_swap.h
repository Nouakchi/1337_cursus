/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:42:56 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 10:43:32 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void    exit_error(void);

int     ft_isDigit(char *str);
int     ft_inList(t_list *lst, int number);
void    ft_freeArgs(char **arr);
int     ft_lst_insert(t_list **lst, char *arg, char **args);

# endif