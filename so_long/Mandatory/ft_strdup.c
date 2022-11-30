/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:39:18 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:54:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = ft_strlen(s1) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len);
	return (res);
}
