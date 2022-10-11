

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    unsigned char *_s1;
    unsigned char *_s2;

    _s1 = (unsigned char *)s1;
    _s2 = (unsigned char *)s2;
    i = 0;
    while ((_s1[i] == _s2[i]) && (_s1[i] != '\0' && _s2[i] != '\0') && i < n - 1)
        i++;
    return (_s1[i] - _s2[i]);
}