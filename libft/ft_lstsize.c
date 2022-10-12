/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:50:42 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/12 19:09:05 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
  int count;
  t_list *ptr;
  
  count = 0;
  ptr = lst;
  while(ptr)
    {
      count++;
      ptr = ptr->linker;
    }
  return (count);
}