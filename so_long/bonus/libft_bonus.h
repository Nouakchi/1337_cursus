
#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include<stdlib.h> 
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strchr(const char *s, int c);
char	*ft_truncate_left(char *str);
char	*ft_truncate_right(char **str);
char	*ft_read_line(int fd, char *reserve);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif