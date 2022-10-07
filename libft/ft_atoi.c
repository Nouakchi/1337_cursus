

#include "libft.h"

int ft_atoi(const char *str)
{
    int res;
    int sign;

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
    return (res * sign);
}

int main()
{
    char buffer[] = "   -2147483648";
    printf("%d", ft_atoi(buffer));
}