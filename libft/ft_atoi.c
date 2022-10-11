

#include "libft.h"

int ft_atoi(const char *str)
{
    unsigned int res;
    unsigned int sign;

    res = 0;
    sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    while (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {   
        res = res * 10 + *str - 48;
        str++;
    }
    res *= sign;
    return (res);
}