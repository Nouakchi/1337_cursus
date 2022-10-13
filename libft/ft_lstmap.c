/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:51:48 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/13 11:27:25 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *res;
  t_list *ptr;
  
  ptr = lst;
  res = ft_lstnew(ptr->content);
  ptr = ptr->next;
  while (ptr)
  {
    ft_lstadd_back(&res, ft_lstnew(ptr->content));
    f(res);
    del(res);
    ptr = ptr->next;
  }
  free(lst);
  return (res);
}

/*
#include <stdlib.h>

typedef struct s_list
{
int content;
struct s_list *next;
} t_list;

t_list *ft_lstlast(t_list *lst)
{
  t_list *ptr;
  
  if (lst == ((void *)0))
    return ((void *)0);
  ptr = lst;
  while (ptr->next)
    ptr = ptr->next;
  return (ptr);
}

t_list *ft_lstnew(void *content)
{
  t_list *node;
  
  node = malloc(sizeof(t_list));
  if (!node)
    return (NULL);
  node->content= (char *)content;
  node->next = NULL;
  return (node);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
  t_list *ptr;
  
  if (lst)
  {
    if (*lst == NULL)
      *lst = new;
    else
    {
      ptr = ft_lstlast(*lst);
      ptr->next = new;
    }
  }
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *res;
  t_list *ptr;
  
  ptr = lst;
  res = ft_lstnew(ptr->content);
  ptr = ptr->next;
  while (ptr)
  {
    ft_lstadd_back(&res, ft_lstnew(ptr->content));
    ptr = ptr->next;
  }
  free(ptr);
  return (res);
}
int f(){}
int del(){}

int main()
{
  t_list *node;

  node = ft_lstnew(1);
  node->next = ft_lstnew(2);
  node->next->next = ft_lstnew(3);
  ft_lstmap(node,f,del);
}
*/
