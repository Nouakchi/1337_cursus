/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:28:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:35:53 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_is_digit(char *str)
{
	while (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_in_list(t_list *lst, int number)
{
	while (lst)
	{
		if (lst->content == number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_free_args(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	ft_lst_insert(t_list **lst, char *arg, char **args)
{
	if (!ft_is_digit(arg) || !ft_in_list(*lst, ft_atoi(arg))
		|| !ft_strlen(arg))
	{
		ft_free_args(args);
		ft_lstclear(lst, NULL);
		return (0);
	}
	else
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(arg)));
	return (1);
}
