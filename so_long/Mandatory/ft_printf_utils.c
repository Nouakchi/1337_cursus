/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:39:00 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:55:28 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter = *counter + 1;
}

void	ft_putstr(char *s, int *counter)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*counter += 6;
	}
	else
		while (*s)
			ft_putchar(*s++, counter);
}

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putstr("-2", counter);
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', counter);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		ft_putchar(n + 48, counter);
}

void	ft_putnbr_base(unsigned int n, int sign, int *counter)
{
	char			*base;

	if (sign == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_base(n / 16, sign, counter);
		ft_putnbr_base(n % 16, sign, counter);
	}
	else
		ft_putchar(base[n], counter);
}

void	ft_put_adrss(unsigned long n, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_adrss(n / 16, counter);
		ft_put_adrss(n % 16, counter);
	}
	else
		ft_putchar(base[n], counter);
}
