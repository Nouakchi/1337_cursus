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

    i = 0;
    if (dst < src)
        while (i < len)
        {
            ((char *)dst)[i] = ((char *)src)[i];
            i++;
        }
    else
    {
        i = len - 1;
        while (i >= 0)
        {
            ((char *)dst)[i] = ((char *)src)[i];
            i--;
        }
    }
    return (dst);
}
