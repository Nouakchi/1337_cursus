/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:50:42 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 12:01:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	count = 0;
	ptr = lst;
	while (ptr)
	{
			count++;
			ptr = ptr->next;
	}
	return (count);
}
