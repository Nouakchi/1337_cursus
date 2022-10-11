

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t lres;
    size_t size;

    if (!s)
        return (NULL);
    lres = ft_strlen(&s[start - 1]);
    size = (lres < len) ? lres : len;
    res = (char *)malloc((size + 1) * sizeof(char));
    if (!res)
        return (NULL);
    ft_strlcpy(res, &s[start - 1], (lres < len) ? lres + 1 : len + 1);
    return (res);
}