/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:57:05 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/22 23:53:52 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	static int		check = -2;
	static char		*reserve = "";
	char			*res;

	if (check == -1 || reserve == NULL)
		return (NULL);
	if (ft_strchr(reserve, '\n') != NULL)
	{
		res = ft_truncate(reserve);
		while (*reserve && *reserve != '\n')
			reserve++;
		reserve++;
		return (res);
	}
	while (check != 0 && ft_strchr(buff, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		buff[check] = '\0';
		reserve = ft_strjoin(reserve, buff);
	}
	return (ft_check(&reserve, &res));
}

// int main()
// {
// 	int fd = open("test.txt", O_RDWR);
// 	// char *s = get_next_line(fd);
// 	// while (s)
// 	// {
// 	// 	printf("%s", s);
// 	// 	s = get_next_line(fd);
// 	// }
// }