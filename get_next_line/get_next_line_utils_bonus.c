/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:06:42 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/29 00:14:14 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	rsize;

	if (!*s1)
	{
		*s1 = (char *)malloc(1 * sizeof(char));
		*s1[0] = '\0';
	}
	if (!*s1 || !*s2)
		return (NULL);
	rsize = (ft_strlen(*s1) + ft_strlen(*s2) + 1);
	res = (char *)malloc(rsize * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	j = -1;
	while ((*s2)[++j])
		res[i++] = (*s2)[j];
	res[i] = '\0';
	free(*s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_truncate_left(char *str)
{
	int		len;
	char	*res;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	res = malloc((len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		res[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		res[len] = str[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_truncate_right(char **str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
			i++;
	if (!(*str)[i])
	{
		free(*str);
		return (NULL);
	}
	len = i + 1;
	while ((*str)[len])
		len++;
	res = malloc((len - i) * sizeof(char));
	if (!res)
		return (NULL);
	len = i + 1;
	i = 0;
	while ((*str)[len])
		res[i++] = (*str)[len++];
	res[i] = '\0';
	free(*str);
	return (res);
}
