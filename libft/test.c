typedef struct s_lst{
  int content;
  struct s_lst *linker;
} t_lst;

#include <stdlib.h>

t_lst *ft_lstnew(int content)
{
  t_lst *node;
  
  node = malloc(sizeof(t_lst));
  node->content= content;
  node->linker = NULL;
  return (node);
}

void ft_lstadd_front(t_lst **lst, t_lst *_new)
{
  _new->linker = *lst;
  *lst = _new;
}

int ft_lstsize(t_lst *lst)
{
  int count;
  t_lst *ptr;
  
  count = 0;
  ptr = lst;
  while(ptr)
    {
      count++;
      ptr = ptr->linker;
    }
  return (count);
}

t_lst *ft_lstlast(t_lst *lst)
{
  t_lst *ptr;
  
  ptr = lst;
  while (ptr->linker)
    ptr = ptr->linker;
  return (ptr);
}

void ft_lstadd_back(t_lst **lst, t_lst *_new)
{
  t_lst *ptr;
  
  ptr = ft_lstlast(*lst);
  ptr->linker = _new;
}
/*
void del(void *args)
{
  args->content = 0;
}

void ft_lstdelone(t_lst *lst, void (*del)(void*))
{
  del(lst);
  free(lst);
}
*/
/*
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
*/
/*
void ft_lstiter(t_list *lst, void (*f)(void *))
{
  t_lst ptr;
  
  ptr = lst;
  while (ptr)
  {
    f(ptr->content);
    ptr = ptr->linker;
  }
}
*/

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
// void (*del)(void *))
// {
//   t_lst ptr;
//   t_lst res;
  
//   ptr = lst;
//   res = (t_lst *)malloc(sizeof(t_lst));
//   while (ptr)
//   {
//     res->linker = f(ptr);
//     ptr = ptr->linker;
//   }
// }

int main()
{
    t_lst *node = ft_lstnew(1);
    ft_lstadd_front(&node, ft_lstnew(2));
    int size = ft_lstsize(node);
    t_lst *last_node = ft_lstlast(node);
    ft_lstadd_back(&node, ft_lstnew(3));
    ft_lstdelone(last_node, del);
    return 0;
}