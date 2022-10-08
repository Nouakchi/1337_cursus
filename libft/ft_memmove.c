/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:01:44 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/06 20:01:53 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    i = -1;
    if (dst < src)
        while (++i < len)
            ((char *)dst)[i] = ((char *)src)[i];
    else
        while (--len >= 0)
            ((char *)dst)[len] = ((char *)src)[len];
    return (dst);
}
