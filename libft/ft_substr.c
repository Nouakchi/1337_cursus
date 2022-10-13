

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t ls;
    //size_t size;
    size_t i;

    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        ls = 0;
    else
        ls = (start == 0) ? ft_strlen(s) : ft_strlen(s + start - 1);
    len = (ls >= len) ? len : ls; 
    res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while(s[start] && i < len)
        res[i++] = s[start++];
    res[i] = '\0';
    return (res);
}
