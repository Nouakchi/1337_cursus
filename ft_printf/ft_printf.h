/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:11:17 by onouakch          #+#    #+#             */
/*   Updated: 2022/10/29 00:01:12 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putnbr_base(unsigned int n, int sign, int *counter);
void	print(const char *str, va_list ap, int *counter);
int		ft_printf(const char *str, ...);
void	ft_put_u_nbr(unsigned int n, int *counter);
void	ft_put_adrss(unsigned long long n, int *counter);

#endif