
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t res;

    if (dstsize == 0 || dstsize <= ft_strlen(dst))
      return (ft_strlen(src) + dstsize);
    res = (dstsize > ft_strlen(dst)) ? ft_strlen(dst) + ft_strlen(src) : ft_strlen(src) + dstsize;
    i = ft_strlen(dst);
    while (*src && i + 1 < dstsize)
    {
      dst[i] = *src;
      i++;
      src++;
    }
    
    dst[i] = '\0';
    return (res);
}