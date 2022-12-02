#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void    push_swap(int *s_a, int *s_b)
{

}

size_t  is_integer(char *str)
{
    size_t  res;

    res = 0;
    while (*str)
    {
        res = (res * 10) + (*str - 48);
        str++;
    }
    return (res >= -2147483648 && res <= 2147483647);
}

int is_digit(char *str)
{
    if (*str != '-' && *str != '+'
        && !(*str >= '0' && *str <= '9'))
        return (0);
    str++;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int av_len;

    av_len = 0;
    if (ac > 1)
    {
        while (++av_len < ac)
            if (!is_digit(av[av_len]) || !is_integer(av[av_len]))
                return (printf("Error\n"), 0);
    }
    return (0);
}