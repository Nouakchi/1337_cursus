

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    int len;
    int i;

    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = -1;
    while (++i < len)
        res[i] = f(i, s[i]);
    res[i] = '\0';
    return (res);
}