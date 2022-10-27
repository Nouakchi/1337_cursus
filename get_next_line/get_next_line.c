<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:05:17 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/27 20:05:41 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *reserve)
{
	char	*buff;
=======

#include "get_next_line.h"

char *ft_read_line(int fd, char *reserve)
{
	char			*buff;
>>>>>>> 93c1de0b0e43cecccdc7fbee6eeed215ca0561b3
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
<<<<<<< HEAD
	static char	*reserve = NULL;
	char		*result;
=======
	static char		*reserve = NULL;
	char *result;
>>>>>>> 93c1de0b0e43cecccdc7fbee6eeed215ca0561b3

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	reserve = ft_read_line(fd, reserve);
	if (!reserve)
<<<<<<< HEAD
		return (NULL);
=======
		return(NULL);
>>>>>>> 93c1de0b0e43cecccdc7fbee6eeed215ca0561b3
	result = ft_truncate_left(reserve);
	reserve = ft_truncate_right(&reserve);
	return (result);
}
