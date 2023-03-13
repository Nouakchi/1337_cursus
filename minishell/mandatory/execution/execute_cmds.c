/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:19:12 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:31 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_allocate_pipes(t_seer *seer)
{
	int	i;

	if (seer->num_pipes)
	{
		seer->fd = ft_calloc(seer->num_pipes, sizeof(int *));
		if (!seer->fd)
			return (ft_perror(ERR_PROMPT, "CALLOC"), errno);
	}
	i = 0;
	while (i < seer->num_pipes)
	{
		seer->fd[i] = ft_calloc(2, sizeof(int));
		if (!seer->fd[i])
			return (ft_perror(ERR_PROMPT, "CALLOC"), errno);
		if (pipe(seer->fd[i]) == -1)
			return (ft_perror(ERR_PROMPT, "pipe"), errno);
		i++;
	}
	return (0);
}

void	ft_execute_batch_singles(t_seer *seer)
{
	t_cmds	*tempcmds;

	tempcmds = seer->cmds;
	while (tempcmds)
	{
		seer->exit_num = execute_single(tempcmds, seer);
		tempcmds = tempcmds->next;
	}
}

unsigned char	execute_cmds(t_seer *seer)
{
	int		status;
	int		result;

	result = ft_allocate_pipes(seer);
	if (result)
		return (result);
	ft_execute_batch_singles(seer);
	close_pipes(seer, NULL, NULL);
	result = errno;
	if (seer->num_pipes != 0)
	{
		waitpid(seer->last_pid, &status, 0);
		while (wait(NULL) > 0)
			;
		seer->exit_num = WEXITSTATUS(status);
		errno = result;
		return (WEXITSTATUS(status));
	}
	else if (!seer->cmds->cmd || !is_builtin(seer->cmds->cmd))
	{
		wait(&status);
		seer->exit_num = WEXITSTATUS(status);
	}
	errno = result;
	return (seer->exit_num);
}
