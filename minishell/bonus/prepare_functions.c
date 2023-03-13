/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:16:11 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:43 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_inoutfiles	*new_inoutfile(char *inoutfile_name, int type, int flag)
{
	t_inoutfiles	*inoutfile;

	inoutfile = malloc(sizeof(t_inoutfiles));
	if (!inoutfile)
		return (NULL);
	inoutfile->inoutfile_name = ft_strdup(inoutfile_name);
	inoutfile->type = type;
	inoutfile->flag = flag;
	inoutfile->next = NULL;
	return (inoutfile);
}

void	append_inoutfile(t_inoutfiles **inoutfile, t_inoutfiles *new_inoutfile)
{
	t_inoutfiles	*temp;

	if (!inoutfile)
		return ;
	if (!*inoutfile)
	{
		*inoutfile = new_inoutfile;
		return ;
	}
	temp = *inoutfile;
	while (temp->next)
		temp = temp->next;
	temp->next = new_inoutfile;
}

t_heredocs	*new_heredoc(char *heredoc_name, char *delimiter)
{
	t_heredocs	*heredoc;

	heredoc = malloc(sizeof(t_heredocs));
	if (!heredoc)
		return (NULL);
	heredoc->heredoc_name = ft_strdup(heredoc_name);
	heredoc->delimiter = ft_strdup(delimiter);
	heredoc->next = NULL;
	return (heredoc);
}

void	append_heredoc(int *in_cmd, t_cmds **cmds,
		t_heredocs **heredoc, t_heredocs *new_heredoc)
{
	t_heredocs	*temp;

	(void)in_cmd;
	(void)cmds;
	if (!heredoc)
		return ;
	if (!*heredoc)
	{
		*heredoc = new_heredoc;
		return ;
	}
	temp = *heredoc;
	while (temp->next)
		temp = temp->next;
	temp->next = new_heredoc;
}

t_cmds	*new_cmd(int num_cmd, char *cmd)
{
	t_cmds	*cmds;

	cmds = ft_calloc(1, sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	cmds->num_cmd = num_cmd;
	cmds->cmd = cmd;
	cmds->next = NULL;
	return (cmds);
}
