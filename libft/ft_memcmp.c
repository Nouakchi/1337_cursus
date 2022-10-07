

#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    char *_s1;
    char *_s2;

    i = 0;
    _s1 = (char *)s1;
    _s2 = (char *)s2;
    while ((_s1[i] == _s2[i]) && (_s1[i] != '\0' && _s2[i] != '\0') && i < n - 1)
        i++;
    return (_s1[i] - _s2[i]);
}