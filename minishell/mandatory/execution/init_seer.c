/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_seer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:59 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:51 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_seer(t_seer *seer)
{
	seer->in = 0;
	seer->out = 1;
	if (!seer->pwd)
		seer->pwd = getcwd(NULL, 0);
}

void	init_in_out_seer(t_cmds *cmds, t_seer *seer)
{
	if (cmds->num_cmd != 0)
		seer->in = seer->fd[cmds->num_cmd -1][0];
	if (cmds->num_cmd != seer->num_pipes)
		seer->out = seer->fd[cmds->num_cmd][1];
}

void	init_readline(void)
{
	rl_catch_signals = 0;
	rl_outstream = stderr;
}

void	init_all(t_seer **seer, char *envp[])
{
	*seer = ft_calloc(1, sizeof(t_seer));
	g_global.environment = get_environment(envp);
	if (!seer)
		return (perror("minishell"), exit(errno));
	initialize_hardcoded_paths(*seer);
	index_export();
	init_seer(*seer);
	init_readline();
	signal(SIGINT, interrupt_handler);
	signal(SIGQUIT, quit_handler);
}

int	ft_spaces_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
