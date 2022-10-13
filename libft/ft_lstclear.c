/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:23 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/13 09:06:22 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
  t_list *tmp;
  
  if (lst && del)
  {
    while (*lst)
    {
      tmp = (*lst)->next;
      ft_lstdelone(*lst, del);
      *lst = (*lst)-> next;
    }
    free(tmp);
  }
}