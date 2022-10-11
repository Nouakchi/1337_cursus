
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;
    size_t pos;
    size_t check;

    i = -1;
    if ((!haystack || !needle) && len == 0)
        return (NULL);
    if (ft_strlen(needle) == 0)
        return ((char *)haystack);
    while (haystack[++i] && i < len)
    {
        if (haystack[i] == needle[0])
        {
            pos = i;
            j = 0;
            check = 1;
            while (needle[++j] && ++i < len)
                if (haystack[i] == needle[j])
                    check++;
            if  (check == ft_strlen(needle))
                return ((char *)&haystack[pos]);
            i = pos;
        }
    }
    return (NULL);
}