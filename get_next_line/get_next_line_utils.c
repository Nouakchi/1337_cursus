/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:59:10 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/24 20:46:13 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h> 
#include	<unistd.h> 
#include	<fcntl.h> 
#include	<stdlib.h>
#include	<string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(const char *s1)
{
	size_t		len;
	char	*res;
	int		i;	
	len = ft_strlen(s1) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
	        return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	rsize;

	if (!*s1 && !*s2)
		return (NULL);
	if (!*s1)
		return (strdup(*s2));
	if (!*s2)
		return (*s1);
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
