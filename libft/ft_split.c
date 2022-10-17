/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:22:28 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/17 10:37:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char sprt)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str && *str == sprt)
			str++;
		if (*str)
			counter++;
		while (*str && !(*str == sprt))
			str++;
	}
	return (counter);
}

char	*stralloc(const char *s, int len)
{
	char	*res;
	int		i;

	i = -1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (s[++i] && i < len)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

void	*fr_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	size_t	len;
	int		words;

	if (!s)
		return (0);
	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = -1;
	while (++i < words)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s++ && !(*s == c))
			len++;
		res[i] = stralloc(s - len - 1, len + 1);
		if (!res[i])
			return (fr_tab(res));
	}
	res[i] = NULL;
	return (res);
}
