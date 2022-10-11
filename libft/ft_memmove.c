/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:01:44 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/10 12:19:23 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    i = -1;
    if (src == dst || !len)
        return (dst);
    if (dst < src)
        ft_memcpy(dst, src, len);
    else
        while (len-- > 0)
            ((char *)dst)[len] = ((char *)src)[len];
    return (dst);
}
