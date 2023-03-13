/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:12:04 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:22:03 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clean_inoutfiles(t_inoutfiles *inoutfile)
{
	t_inoutfiles	*temp;
	t_inoutfiles	*curr;

	curr = inoutfile;
	while (curr)
	{
		temp = curr->next;
		free(curr->inoutfile_name);
		free(curr);
		curr = temp;
	}
}

void	clean_heredocs(t_heredocs *heredoc)
{
	t_heredocs	*temp;
	t_heredocs	*curr;

	curr = heredoc;
	while (curr)
	{
		temp = curr->next;
		unlink(curr->heredoc_name);
		free(curr->heredoc_name);
		free(curr->delimiter);
		free(curr);
		curr = temp;
	}
}

void	garbage_collector_v2(t_seer *seer)
{
	t_cmds	*curr;
	t_cmds	*temp;

	curr = seer->cmds;
	while (curr)
	{
		temp = curr->next;
		free(curr->cmd);
		free_bins(curr->args);
		clean_inoutfiles(curr->inoutfiles);
		clean_heredocs(curr->heredocs);
		free(curr);
		curr = temp;
	}
	errno = 0;
}

void	garbage_collector(t_seer *seer)
{
	t_cmds	*curr;
	t_cmds	*temp;
	int		i;

	i = -1;
	while (++i < seer->num_pipes)
		free(seer->fd[i]);
	free(seer->fd);
	seer->fd = NULL;
	curr = seer->cmds;
	while (curr)
	{
		temp = curr->next;
		free(curr->cmd);
		free_bins(curr->args);
		clean_inoutfiles(curr->inoutfiles);
		clean_heredocs(curr->heredocs);
		free(curr);
		curr = temp;
	}
	errno = 0;
}
