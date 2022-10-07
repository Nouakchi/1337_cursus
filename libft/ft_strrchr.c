

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    if (!s)
        return (NULL);
    while (s[i] >= 0)
        if (s[i] == c)
            return (&((char *)s)[i]);
        else
            i--;
    return (NULL);
}