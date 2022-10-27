/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:03:09 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/27 20:33:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *reserve)
{
	char	*buff;
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
	static char	*reserve[4096];
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	reserve[fd] = ft_read_line(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	result = ft_truncate_left(reserve[fd]);
	reserve[fd] = ft_truncate_right(&reserve[fd]);
	return (result);
}
