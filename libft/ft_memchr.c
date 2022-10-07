

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;

    i = -1;
    while (((char *)s)[++i])
        if (((char *)s)[i] == c)
            return (&((char *)s)[i]);
    return (NULL);
}