/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:50:42 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 15:41:10 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	if(!lst)
		return 0;
	count = 0;
	ptr = lst;
	while (ptr)
	{
			count++;
			ptr = ptr->next;
	}
	return (count);
}
