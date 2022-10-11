/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:35:30 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/10 12:41:09 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    size_t i;

    i = 0;
    while(i < len)
        ((char *)b)[i++] = c;
    return b;
}
