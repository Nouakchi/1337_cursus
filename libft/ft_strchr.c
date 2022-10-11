

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    while (*s)
        if (*s == c)
            return ((char *)s);
        else 
            s++;
    if (*s == c)
        return ((char *)s);
    else
        return (NULL);
}