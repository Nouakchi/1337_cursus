#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// char *str;

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char **s1, char s2)
// {
// 	char	*res;
// 	size_t	i;
// 	size_t	j;
// 	size_t	rsize;

// 	if (!*s1)
// 	{
// 		*s1 = (char *)malloc(1 * sizeof(char));
// 		*s1[0] = '\0';
// 	}
// 	if (!*s1 || !s2)
// 		return (NULL);
// 	rsize = (ft_strlen(*s1) + 2);
// 	res = (char *)malloc(rsize * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	i = -1;
// 	while ((*s1)[++i])
// 		res[i] = (*s1)[i];
// 	j = -1;
// 	res[i++] = s2;
// 	res[i] = '\0';
// 	free(*s1);
// 	return (res);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*res;
// 	size_t	ls;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		ls = 0;
// 	else
// 	{
// 		if (start == 0)
// 			ls = ft_strlen(s);
// 		else
// 			ls = ft_strlen(s + start - 1);
// 	}
// 	if (ls < len)
// 		len = ls;
// 	res = (char *)malloc((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (s[start] && i < len)
// 		res[i++] = s[start++];
// 	res[i] = '\0';
// 	return (res);
// }

// int bin_to_int(char *str)
// {
//     int res;
//     int i;
//     int j;

//     res = 0;
//     i = 0;
//     j = 7;
//     while (j + 1 > 0)
//     {
//         if (str[i++] == '1')
//             res += (1 << j);
//         j--;
//     }
//     return (res);
// }

// void    ft_putchar(char c)
// {
//     write(1, &c, 1);
// }


// void handle_sig1(int signum)
// {
//     str = ft_strjoin(&str, '1');
// }

// void handle_sig2(int signum)
// {
//     str = ft_strjoin(&str,'0');
// }

void handle(int signum)
{
    static int c;
    static int bit;

    c |= (signum == SIGUSR1);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
    c <<= 1;
}

// void finish(int signum)
// {
//     int i;
//     int j;
//     int len;

//     i = 0;
//     len = ft_strlen(str);
//     while (i < len)
//     {
//         ft_putchar(bin_to_int(ft_substr(str, i, i + 8)));
//         i += 8;
//     }
//     write(1, "\n", 1);
//     free(str);
//     str = NULL;
// }

int main(int ac, char *av[])
{
    printf("%d \n", getpid());
    while (1)
    {
        signal(SIGUSR1, handle);
        signal(SIGUSR2, handle);
        pause();
    }
}