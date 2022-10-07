

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *res;

    res = malloc(count * size);
    ft_bzero(res,count * size);
    return (res);
}