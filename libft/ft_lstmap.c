/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:51:48 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/22 09:58:21 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*ptr;

	if (!f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		ptr = ft_lstnew(f(lst->content));
		if (!ptr)
			ft_lstclear(&lst, del);
		ft_lstadd_back(&res, ptr);
		lst = lst->next;
	}
	return (res);
}
