/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:51:48 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 12:16:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, int*(*f)(int), void (*del)(int))
{
	t_list	*res;
	t_list	*ptr;

	if (!f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		ptr = ft_lstnew(*f(lst->content));
		if (!ptr)
			ft_lstclear(&lst, del);
		ft_lstadd_back(&res, ptr);
		lst = lst->next;
	}
	return (res);
}
