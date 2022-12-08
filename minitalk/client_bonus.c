/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:52:34 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/08 18:02:10 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;

	res = 0;
	sign = 1;
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
		str++;
	}
	if (res >= (size_t) -1 / 2 && sign > 0)
		return (-1);
	if (res > (size_t) -1 / 2 && sign < 0)
		return (0);
	res *= sign;
	return ((int)res);
}

void	confirm(int signum)
{
	(void)signum;
	write(1, "Your message is send successfully\n", 35);
}

void	str_to_binary(int pid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		j--;
	}
}

void	send_mssg(pid_t pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str_to_binary(pid, str[i]);
	str_to_binary(pid, '\0');
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid > 0)
		{
			signal(SIGUSR2, confirm);
			send_mssg(pid, av[2]);
		}
		else
			write(1, "Invalid PID !!\n", 15);
	}
	else
		write(1, "Invalid args !!\n", 16);
	return (0);
}
