

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *res;
    int i;
    size_t rsize;

    if (!s1 || !s2)
        return (NULL);
    rsize = (ft_strlen(s1) + ft_strlen(s2) + 1);
    res = (char *)malloc(rsize * sizeof(char));
    if (!res)
        return (NULL);
    i = -1;
    ft_strlcpy(res, s1, rsize);
    ft_strlcat(res, s2, rsize);
    return (res);
}