/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:23 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 12:10:23 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*ptr;

	if (lst && del)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = ptr;
		}
	}
}
