/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:43:33 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/10 17:43:34 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(const char *s1, const char *s2)
{
	char	*msg;

	msg = ft_strjoin(s1, s2);
	perror(msg);
	free(msg);
}
