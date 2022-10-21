/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:25:20 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/20 20:48:00 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	rsize;

	if (!s1 || !s2)
		return (NULL);
	rsize = (ft_strlen(s1) + ft_strlen(s2) + 1);
	res = (char *)malloc(rsize * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, rsize);
	ft_strlcat(res, s2, rsize);
	return (res);
}
