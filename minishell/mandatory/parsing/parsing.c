/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:22 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:54 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_go_next(t_token token[])
{
	char	*tmp;

	tmp = token[0].value;
	token[0].value = ft_strdup(token[1].value);
	free(tmp);
	free(token[1].value);
	token[1].value = ft_strdup("");
}

char	*ft_check_op(char *cmd)
{
	int		i;
	char	*str;
	char	*tmp;

	i = -1;
	str = NULL;
	if (!ft_strchr(cmd, '<') && !ft_strchr(cmd, '>'))
		return (cmd);
	while (cmd[++i])
		if ((cmd[i] == '>' || cmd[i] == '<') && cmd[i + 1] != ' ')
			ft_update_op(str, &cmd, &i);
	if (cmd[0] == ' ')
	{
		tmp = cmd;
		cmd = ft_substr(cmd, 1, ft_strlen(cmd));
		free(tmp);
	}
	return (cmd);
}

int	ft_update_parser(int *index, int *in_quote, t_token *n_token, char *cmd)
{
	static char	last_op = '\0';

	if (last_op == '\0')
	{
		last_op = cmd[*index];
		*in_quote = 1;
		n_token->t_in_q = 1;
	}
	else if (*in_quote && last_op == cmd[*index])
	{
		*in_quote = 0;
		last_op = '\0';
	}
	return (0);
}

void	ft_prepare_cmd(int *in_cmd, t_cmds **cmds, t_seer *seer, t_token *tok)
{
	char	*tmp;

	if (!(!ft_strcmp(tok[0].value, "<<") && tok[1].value[0] == '"'
			&& ft_strchr(tok[1].value, '$')))
		tok[1].value = ft_check_sign((t_vars){in_cmd, &tok[1].value},
				seer, cmds);
	else
	{
		tmp = tok[1].value;
		tok[1].value = ft_strtrim(tok[1].value, "\"");
		free(tmp);
	}
}

t_cmds	*ft_parser(char *cmd, t_seer *seer)
{
	t_cmds	*cmds;
	t_token	tok[2];
	t_vars1	vars;
	int		i;

	ft_init(tok, &i, &vars.in_quote, &vars.in_cmd);
	cmds = NULL;
	cmd = ft_check_op(cmd);
	while (cmd[++i])
	{
		if (ft_checker(cmd, &i, &vars.in_quote, &tok[1]) == -1)
			return (free(tok[1].value), free(tok[0].value), free(cmd), cmds);
		if ((cmd[i] == ' ' || cmd[i] == '|') && vars.in_quote == 0)
		{
			if (cmd[i] == ' ' && (cmd[i - 1] == '|' || cmd[i - 1] == ' '
					|| cmd[i + 1] == '|' || cmd[i + 1] == ' '))
				continue ;
			ft_prepare_cmd(&vars.in_cmd, &cmds, seer, tok);
			ft_getcmd(&vars.in_cmd, tok, &cmds, &cmd[i - 1]);
			continue ;
		}
		ft_join(&tok[1], cmd, i);
	}
	seer->num_pipes = ft_lastcmd(&cmds)->num_cmd;
	return (free(tok[1].value), free(tok[0].value), free(cmd), cmds);
}
