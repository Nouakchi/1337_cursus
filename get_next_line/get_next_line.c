/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:57:05 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/25 20:41:54 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_line(int fd, char *reserve)
{
	char			*buff;
	int		check;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	check = 1;
	while (check != 0 && ft_strchr(reserve, '\n') == NULL)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[check] = '\0';
		reserve = ft_strjoin(&reserve, &buff);
	}
	free(buff);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char		*reserve = NULL;
	char *result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	reserve = ft_read_line(fd, reserve);
	if (!reserve)
		return(NULL);
	result = ft_truncate_left(reserve);
	reserve = ft_truncate_right(&reserve);
	return (result);
}

// int main()
// {
// 	int fd = open("./gnlTester/files/nl", O_RDWR);
// 	char *line;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break;
// 		free(line);
// 	}
//  	close(fd);
// }
