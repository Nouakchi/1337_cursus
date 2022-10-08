

#include "libft.h"



char *ft_strtrim(char const *s1, char const *set)
{
    int set_occ;
    int i;
    char *res;

    set_occ = 0;
    i = -1;
    if (!s1 || !set)
        return (NULL);
    while (s1[++i])
        if (ft_strchr(set, s1[i]) != NULL)
            set_occ++;
    res = (char *)malloc((ft_strlen(s1) - set_occ + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = -1;
    while (s1[++i])
        if (ft_strchr(set, s1[i]) == NULL)
        {
            *res = s1[i];
            res++;
        }
    *res = '\0';
    return (res - (ft_strlen(s1) - set_occ));
}