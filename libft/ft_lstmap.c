/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:51:48 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/12 21:46:55 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *ptr;
  t_list *res;
  
  ptr = lst;
  res = (t_list *)malloc(sizeof(t_list));
  while (ptr)
  {
    res->next = f(ptr);
    del(ptr);
    ptr = ptr->next;
  }
  free(ptr);
  return (res);
}