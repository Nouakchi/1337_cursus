/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:49:09 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/08 14:43:16 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	handle(int signum, siginfo_t *info, void *s)
{
	static pid_t	pid;
	static char		c;
	static int		bit;

	(void)s;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		c = 0;
		bit = 0;
		pid = info->si_pid;
	}
	c |= (signum == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			c = 0;
			bit = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			write(1, &c, 1);
			c = 0;
			bit = 0;
		}
		usleep(100);
	}
	c <<= 1;
}

void	ft_putnbr(int n)
{
	int	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &handle;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
