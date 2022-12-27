/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:51:14 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 12:10:55 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
