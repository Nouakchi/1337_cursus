/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:38:40 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/30 11:55:28 by onouakch         ###   ########.fr       */
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
		ft_put_adrss(va_arg(ap, unsigned long), counter);
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
	int			counter;

	va_start(ap, str);
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
			{
				write(1, "", 1);
				break ;
			}
			else
				print(str + 1, ap, &counter);
			str += 2;
		}
		else
		{
			write(1, str++, 1);
			counter++;
		}
	}
	return (counter);
}
