/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:11:14 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:25:50 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "export") == 0 || ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

unsigned char	ft_exec_cmd(t_cmds *cmds, t_seer *seer)
{
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (echo((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (cd((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (pwd((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		return (export((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (unset((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		return (env((cmds->args) + 1, seer));
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (exitt((cmds->args) + 1, seer));
	else
		return (perror(""), errno);
}

unsigned char	process_infile_safe(t_inoutfiles *inoutfile, t_seer *seer)
{
	if (seer->in != 0)
		close(seer->in);
	seer->in = open(inoutfile->inoutfile_name, O_RDONLY);
	if (seer->in == -1)
		return (ft_perror(ERR_PROMPT, inoutfile->inoutfile_name), errno);
	return (0);
}

unsigned char	process_outfile_safe(t_inoutfiles *inoutfile, t_seer *seer)
{
	int	flag;

	if (seer->out != 1)
		close(seer->out);
	flag = O_CREAT | O_WRONLY | inoutfile->flag;
	seer->out = open(inoutfile->inoutfile_name, flag, 0666);
	if (seer->out == -1)
		return (perror(ERR_PROMPT), errno);
	return (0);
}

unsigned char	process_inoutfile_safe(t_inoutfiles *inoutfile, t_seer *seer)
{
	if (inoutfile->type == INFILE)
		return (process_infile_safe(inoutfile, seer));
	else if (inoutfile->type == OUTFILE)
		return (process_outfile_safe(inoutfile, seer));
	return (1);
}
