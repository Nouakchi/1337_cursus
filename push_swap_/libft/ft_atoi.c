/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:51:28 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 01:15:33 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	long long	res;
	int			sign;
	char		*tmp;

	res = 0;
	sign = 1;
	tmp = str;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		if ((sign > 0 && res > 2147483647) || (sign < 0 && res > 214748648))
			return (exit_error(), 0);
		str++;
	}
	res *= sign;
	return ((int)res);
}
