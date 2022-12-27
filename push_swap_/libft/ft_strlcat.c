/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:25:49 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/16 12:01:08 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	if (dstsize > ft_strlen(dst))
		res = ft_strlen(dst) + ft_strlen(src);
	else
		res = ft_strlen(src) + dstsize;
	i = ft_strlen(dst);
	while (*src && i + 1 < dstsize)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (res);
}
