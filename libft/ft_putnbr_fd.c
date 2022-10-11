

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if (fd > 0)
    {
        if (n == -2147483648)
        {
            n = 147483648;
            ft_putstr_fd("-2", fd);
        }
        if (n < 0)
        {
            n *= -1;
            ft_putchar_fd('-', fd);
        }
        if (n >= 10)
        {
            ft_putnbr_fd(n / 10, fd);
            ft_putnbr_fd(n % 10, fd);
        }
        else
            ft_putchar_fd(n + 48, fd);
    }
}

// int main()
// {
//     ft_putnbr_fd(54351, 1);
// }