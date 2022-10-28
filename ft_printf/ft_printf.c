/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:10:44 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/29 00:00:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u_nbr(unsigned int n, int *counter)
{
	if (n >= 10)
	{
		ft_put_u_nbr(n / 10, counter);
		ft_put_u_nbr(n % 10, counter);
	}
	else
		ft_putchar(n + 48, counter);
}

void	print(const char *str, va_list ap, int *counter)
{
	if (*str == '%')
		ft_putchar('%', counter);
	else if (*str == 'c')
		ft_putchar(va_arg(ap, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), counter);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(ap, int), counter);
	else if (*str == 'p')
	{
		write(1, "0x", 2);
		*counter = *counter + 2;
		ft_put_adrss(va_arg(ap, unsigned long int), counter);
	}
	else if (*str == 'u')
		ft_put_u_nbr(va_arg(ap, unsigned int), counter);
	else if (*str == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), 1, counter);
	else if (*str == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), 0, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			counter;

	va_start(ap, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print(&str[i], ap, &counter);
			i++;
		}
		else
		{
			write(1, &str[i++], 1);
			counter++;
		}
	}
	return (counter);
}
