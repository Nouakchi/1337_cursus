

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t lres;

    if (!s)
        return (NULL);
    lres = ft_strlen(&s[start - 1]);
    if (lres < len)
        res = (char *)malloc((lres + 1) * sizeof(char));
    else
        res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    ft_strlcpy(res, &s[start - 1], (lres < len) ? lres + 1 : len + 1);
    return (res);
}