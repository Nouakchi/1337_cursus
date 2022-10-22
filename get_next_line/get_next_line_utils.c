/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:59:10 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/22 21:28:15 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h> 
#include	<unistd.h> 
#include	<fcntl.h> 
#include	<stdlib.h> 

char *ft_truncate(char *str)
{
	size_t len;
	char	*res;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	res = malloc((len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	len = 0;
	while (str[len] != '\n')
	{
		res[len] = str[len];
		len++;
	}
	res[len] = '\n';
	res[len + 1] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t		i;
	size_t		j;
	size_t	rsize;

	if (!s1 || !s2)
		return (NULL);
	rsize = (ft_strlen(s1) + ft_strlen(s2) + 1);
	res = (char *)malloc(rsize * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i++] = s2[j];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
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
