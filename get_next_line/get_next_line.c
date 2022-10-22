/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:57:05 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/22 08:53:35 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buff;
	size_t	check;
	static char *reserve = "";
	char *res;

	buff = malloc(BUFFER_SIZE + 1);
	check = -1;
	while (check != 0 && ft_strchr(buff, '\n') == NULL)
	{
		check = read(fd, buff, BUFFER_SIZE);
		buff[check] = '\0';
		reserve = ft_strjoin(reserve, buff);
	}
	res = ft_truncate(&reserve);
	printf("%s", reserve);
	return (res);
}

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);
	// get_next_line(fd);
	printf("%s", get_next_line(fd));
}