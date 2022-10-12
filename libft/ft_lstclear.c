/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:23 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/12 20:47:37 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_lst **lst, void (*del)(void*))
{
  t_lst tmp;
  
  while (*lst)
  {
    tmp = *lst->linker;
    ft_lstdelone(lst, del);
    *lst = *lst-> linker;
  }
  free(tmp);
}