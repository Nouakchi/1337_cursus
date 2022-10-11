

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t ls1;

    if (!s1 || !set)
        return (NULL);
    while (*s1 && ft_strchr(set, *s1) != NULL)
        s1++;
    ls1 = ft_strlen(s1) - 1;
    while (ls1 >= 0 && ft_strrchr(set, *(s1 + ls1)) != NULL)
        ls1--;
    return (ft_substr(s1, 0, ls1 + 1));
}
// int main()
// {
//     char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n ";
//     char *s2 = "Hello \t  Please\n Trim me !";
//     char *ret = ft_strtrim(s1, " \n\t");
//     printf("||%s||", ret);
// }