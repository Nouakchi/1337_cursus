/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:23 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/12 21:58:50 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
  t_list *tmp;
  
  while (*lst)
  {
    tmp = (*lst)->next;
    ft_lstdelone(*lst, del);
    *lst = (*lst)-> next;
  }
  free(tmp);
}