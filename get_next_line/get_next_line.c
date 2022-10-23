/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:57:05 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/24 00:20:12 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_truncate_right(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	while (str[i] != '\n')
			i++;
	len = i + 1;
	while (str[len])
		len++;
	res = malloc((len - i) * sizeof(char));
	if (!res)
		return (NULL);
	len = i + 1;
	i = 0;
	while (str[len])
		res[i++] = str[len++];
	res[i] = '\0';
	return (res);
}

char	*ft_check(char **reserve, char *res)
{
	char	*ptr;

	ptr = *reserve;
	if (ft_strchr(*reserve, '\n') != NULL)
	{
		res = ft_truncate_left(*reserve);
		*reserve = ft_truncate_right(ptr);
		free(ptr);
	}
	else
	{
		res = *reserve;
		*reserve = NULL;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static int		check = -2;
	static char		*reserve = NULL;
	char			*res;

	res = NULL;
	if (check == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(reserve, '\n') != NULL)
		return (ft_check(&reserve, res));
	while (check != 0 && ft_strchr(reserve, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		buff[check] = '\0';
		reserve = ft_strjoin(&reserve, &buff);
	}
	return (ft_check(&reserve, res));
}

// int main()
// {
// 	int fd = open("./gnl/files/alternate_line_nl_with_nl", O_RDWR);
// 	char *line;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break;
// 	}
// 	//while(1);
// }