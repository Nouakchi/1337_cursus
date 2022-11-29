/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:32:50 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/29 20:32:51 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int	count_num(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		else
		{
			n *= -1;
			len++;
		}
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc(count_num(n) * sizeof(char));
	if (!res)
		return (NULL);
	i = count_num(n) - 1;
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[i] = '\0';
	while (n != 0)
	{
		res[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}
