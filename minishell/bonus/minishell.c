/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:09:01 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:42 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	g_global;

int	main(int argc, char *argv[], char *envp[])
{
	t_seer	*seer;

	(void)argc;
	(void)argv;
	init_all(&seer, envp);
	shell_loop(seer);
	return (0);
}
