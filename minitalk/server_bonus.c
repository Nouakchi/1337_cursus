/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:49:09 by onouakch          #+#    #+#             */
/*   Updated: 2022/12/08 18:02:15 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	reinitialise(char *c, int *pid, int *bit)
{
	*c = 0;
	*pid = 0;
	*bit = 0;
}

void	handle(int signum, siginfo_t *info, void *s)
{
	static pid_t	pid;
	static char		c;
	static int		bit;

	(void)s;
	if (pid != info->si_pid)
		reinitialise(&c, &pid, &bit);
	c = c << 1 | (signum - SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		reinitialise(&c, &pid, &bit);
	}
	pid = info->si_pid;
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
