/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:54 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:21:55 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	interrupt_handler(int sig)
{
	(void)sig;
	if (g_global.in_read_line == 1)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		write(1, "\n", 1);
		rl_redisplay();
	}
	else
		write(1, "\n", 1);
}

void	quit_handler(int signum)
{
	(void)signum;
}
