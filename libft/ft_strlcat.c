

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    if (dstsize == 0)
      return (ft_strlen(dst) + ft_strlen(src));
    ft_strlcpy(dst + ft_strlen(dst),src,ft_strlen(dst) + ft_strlen(src));
    return (ft_strlen(dst) + ft_strlen(src));
}