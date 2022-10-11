

#include "libft.h"

char *ft_strdup(const char *s1)
{
    int len;
    char *res;

    len = ft_strlen(s1) + 1;
    res = (char *)malloc(len * sizeof(char));
    if (!res)
        return (NULL);
    ft_strlcpy(res, s1, len);
    return (res);
}