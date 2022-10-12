/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:21:31 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/12 19:08:04 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(int content)
{
  t_list *node;
  
  node = malloc(sizeof(t_list));
  node->content= content;
  node->linker = NULL;
  return (node);
}