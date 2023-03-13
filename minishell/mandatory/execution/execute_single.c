/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:17 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:32 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

unsigned char	execute_single(t_cmds *cmds, t_seer *seer)
{
	char	*command;
	char	**env;

	if (cmds->cmd && is_builtin(cmds->cmd))
		return (execute_builtin(cmds, seer));
	seer->last_pid = fork();
	if (seer->last_pid == -1)
		return (ft_perror(ERR_PROMPT, "fork"), errno);
	if (seer->last_pid == 0)
	{
		ft_dup2(cmds, seer);
		command = get_command(cmds, seer);
		if (!command)
			return (ft_perror(ERR_PROMPT, cmds->cmd), exit(errno), errno);
		ft_get_command_check(command);
		env = get_env_arr();
		execve(command, cmds->args, env);
		free(command);
		free_bins(env);
		return (ft_perror(ERR_PROMPT, cmds->cmd), exit(errno), errno);
	}
	return (errno);
}
