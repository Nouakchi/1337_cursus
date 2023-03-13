/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:38:20 by samini            #+#    #+#             */
/*   Updated: 2023/03/10 17:44:04 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_tools
{
	char	*line;
	char	*buf;
	char	*temp;
	ssize_t	retread;
}	t_tools;

int		ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_get_line(char **stash);
int		ft_isline(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
