/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_streams.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:24:21 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:57 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_heredocs_pipeline(t_seer *seer)
{
	t_cmds		*cmd_tmp;

	cmd_tmp = seer->cmds;
	while (cmd_tmp)
	{
		process_heredocs(cmd_tmp, seer);
		cmd_tmp = cmd_tmp->next;
	}
}

void	process_heredocs(t_cmds *cmds, t_seer *seer)
{
	t_heredocs	*temp;

	temp = cmds->heredocs;
	while (temp)
	{
		if (seer->check_sig == 1)
			break ;
		heredoc(temp->heredoc_name, temp->delimiter, temp->in_q, seer);
		temp = temp->next;
	}
}

void	process_infile(t_inoutfiles *infile, t_seer *seer)
{
	t_inoutfiles	*temp;

	temp = infile;
	if (seer->in != 0)
		close(seer->in);
	seer->in = open(temp->inoutfile_name, O_RDONLY);
	if (seer->in == -1)
		return (ft_perror(ERR_PROMPT, temp->inoutfile_name), exit(errno));
}

void	process_outfile(t_inoutfiles *outfile, t_seer *seer)
{
	t_inoutfiles	*temp;
	int				flag;

	temp = outfile;
	if (seer->out != 1)
		close(seer->out);
	flag = O_CREAT | O_WRONLY | temp->flag;
	seer->out = open(temp->inoutfile_name, flag, 0666);
	if (seer->out == -1)
		return (perror(ERR_PROMPT), exit(errno));
}

void	process_inoutfile(t_inoutfiles *inoutfile, t_seer *seer)
{
	if (inoutfile->type == INFILE)
		process_infile(inoutfile, seer);
	else if (inoutfile->type == OUTFILE)
		process_outfile(inoutfile, seer);
}
