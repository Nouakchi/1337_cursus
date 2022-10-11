
#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    if (fd >= 0 && (c >= 0 && c <= 127))
        write(fd, &c, 1);
}