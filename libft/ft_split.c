#include "libft.h"

int	count_words(const char *str, char sprt)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str && *str == sprt)
			str++;
		if (*str)
			counter++;
		while (*str && !(*str == sprt))
			str++;
	}
	return (counter);
}

char    *stralloc(const char *s, int len)
{
    char *res;

    res = ft_strdup(ft_substr(s, 1, len));
    return (res);
}

char    **ft_split(char const *s, char c)
{
    char **res;
    int i;
    size_t len;
    int words;
    
    if (!s)
        return (0);
    words = count_words(s, c);
    res = (char **)malloc((words + 1) * sizeof(char*));
    if (!res)
        return (0);
    i = -1;
    while (++i < words)
    {
        len = 0;
        while (*s && *s == c)
            s++;
		while (*s++ && !(*s == c))
            len++;
        res[i] = stralloc(s - len - 1,len + 1);
    }
    res[i] = NULL;
    return (res);
}
