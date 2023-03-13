/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:47:45 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:23:01 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../includes/minishell.h"

t_cmds	*ft_newcmd(char *cmnd, int flag)
{
	t_cmds		*cmd;
	static int	cmd_index = 0;

	if (flag)
		return (cmd_index = 0, NULL);
	cmd = malloc(sizeof(t_cmds));
	if (!cmd)
		return (NULL);
	cmd->num_cmd = cmd_index++;
	if (!cmnd)
		cmd->cmd = NULL;
	else
		cmd->cmd = ft_strdup(cmnd);
	cmd->args = NULL;
	cmd->heredocs = NULL;
	cmd->inoutfiles = NULL;
	cmd->next = NULL;
	cmd->args_len = 0;
	return (cmd);
}

t_cmds	*ft_lastcmd(t_cmds **cmds)
{
	t_cmds	*tmp;

	if (!*cmds)
		return (NULL);
	tmp = *cmds;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_cmdadd_back(t_cmds **cmds, t_cmds *new)
{
	t_cmds	*tmp;

	if (!*cmds)
	{
		*cmds = new;
		return ;
	}
	tmp = *cmds;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_append_herdoc(int *in_cmd, t_cmds **cmds, t_token tok[], char c)
{
	char	*heredoc_name;

	heredoc_name = generate_heredoc_name();
	ft_check_incmd(in_cmd, cmds);
	append_heredoc(in_cmd, cmds, &ft_lastcmd(cmds)->heredocs,
		new_heredoc(heredoc_name, tok[1].value));
	append_inoutfile(&ft_lastcmd(cmds)->inoutfiles,
		new_inoutfile(heredoc_name, 1, -1));
	ft_lastcmd(cmds)->heredocs->in_q = 0;
	if (c == '"' || c == "'"[0])
		ft_lastcmd(cmds)->heredocs->in_q = 1;
	free(heredoc_name);
}

void	ft_append_cmds(int *in_cmd, t_token tok[], t_cmds **cmds)
{
	t_cmds	*last;

	last = ft_lastcmd(cmds);
	if (!*in_cmd || !ft_lastcmd(cmds)->cmd)
	{
		if (*in_cmd)
		{
			last->cmd = ft_strdup(tok[1].value);
			last->args = ft_arr_additem(last->args, tok[1].value,
					last->args_len);
			last->args_len++;
		}
		else
		{
			ft_cmdadd_back(cmds, ft_newcmd(tok[1].value, 0));
			last = ft_lastcmd(cmds);
			last->args = ft_arr_additem(ft_lastcmd(cmds)->args,
					tok[1].value, ft_lastcmd(cmds)->args_len++);
		}
		ft_lastcmd(cmds)->args_len = 1;
		*in_cmd = 1;
	}
	else
		last->args = ft_arr_additem(ft_lastcmd(cmds)->args,
				tok[1].value, ft_lastcmd(cmds)->args_len++);
}
