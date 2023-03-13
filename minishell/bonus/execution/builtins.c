/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:37:48 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:27:04 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

unsigned char	reset_streams(t_seer *seer, int temp_in, int temp_out)
{
	if (seer->in != 0)
	{
		close(seer->in);
		seer->in = 0;
		if (dup2(temp_in, 0) == -1)
			return (perror(ERR_PROMPT), errno);
		close(temp_in);
	}
	if (seer->out != 1)
	{
		close(seer->out);
		seer->out = 1;
		if (dup2(temp_out, 1) == -1)
			return (perror(ERR_PROMPT), errno);
		close(temp_out);
	}
	return (0);
}

unsigned char	inoutfile_process_loop(t_inoutfiles *temp, t_seer *seer)
{
	while (temp)
	{
		if (process_inoutfile_safe(temp, seer))
			return (seer->in = 0, seer->out = 1, seer->exit_num = errno, errno);
		temp = temp->next;
	}
	return (0);
}

unsigned char	ft_exec_builtin(t_cmds *cmds, t_seer *seer)
{
	int				temp_out;
	int				temp_in;
	unsigned char	result;
	unsigned char	result2;
	t_inoutfiles	*temp;

	temp_out = 0;
	temp_in = 0;
	init_in_out_seer(cmds, seer);
	temp = cmds->inoutfiles;
	if (inoutfile_process_loop(temp, seer))
		return (seer->exit_num);
	if (seer->out != 1)
		temp_out = dup(1);
	if (seer->in != 0)
		temp_in = dup(0);
	if (dup2(seer->out, 1) == -1)
		return (perror(ERR_PROMPT), errno);
	result = ft_exec_cmd(cmds, seer);
	result2 = reset_streams(seer, temp_in, temp_out);
	if (result2)
		return (result2);
	close_pipes(seer, NULL, NULL);
	return (result);
}

unsigned char	execute_builtin(t_cmds *cmds, t_seer *seer)
{
	int	pid;

	if (seer->num_pipes == 0)
		return (ft_exec_builtin(cmds, seer));
	pid = fork();
	seer->last_pid = pid;
	if (pid == -1)
		return (perror(ERR_PROMPT), errno);
	if (pid == 0)
		return (exit(ft_exec_builtin(cmds, seer)), errno);
	return (errno);
}
