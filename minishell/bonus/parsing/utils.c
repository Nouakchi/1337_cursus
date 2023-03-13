/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:47:40 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:25:26 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../includes/minishell.h"

void	ft_join(t_token *n_tok, char *cmd, int index)
{
	char	*tmp;
	char	*tmp_value;

	tmp = ft_substr(cmd, index, 1);
	tmp_value = n_tok->value;
	n_tok->value = ft_strjoin(n_tok->value, tmp);
	free(tmp);
	free(tmp_value);
}

void	ft_check_incmd(int *in_cmd, t_cmds **cmds)
{
	if (!*in_cmd)
	{
		ft_cmdadd_back(cmds, ft_newcmd(NULL, 0));
		*in_cmd = 1;
	}
}

void	ft_add_inoutfile(int *in_cmd, t_cmds **cmds, t_token token[])
{
	t_cmds	*last;
	int		type;
	int		flag;

	ft_check_incmd(in_cmd, cmds);
	last = ft_lastcmd(cmds);
	flag = -1;
	if (!ft_strcmp(token[0].value, "<"))
		type = INFILE;
	else
	{
		type = OUTFILE;
		if (!ft_strcmp(token[0].value, ">>"))
			flag = O_APPEND;
		else
			flag = O_TRUNC;
	}
	append_inoutfile(&last->inoutfiles,
		new_inoutfile(token[1].value, type, flag));
}

void	ft_cut_string(char *str, char **cmd, int *i, char *op)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(*cmd);
	free(*cmd);
	(*cmd) = ft_strjoin(str, op);
	free(str);
	str = ft_substr(tmp, *i + 1, ft_strlen(tmp));
	free(tmp);
	tmp = ft_strdup(*cmd);
	free(*cmd);
	(*cmd) = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	*i += ft_strlen(op) - 1;
}

void	ft_update_op(char *str, char **cmd, int *i)
{
	char	*op;

	op = NULL;
	str = ft_substr((*cmd), 0, *i);
	if ((*cmd)[*i] == '>')
	{
		op = " > ";
		if ((*cmd)[*i + 1] == '>')
		{
			op = " >> ";
			(*i)++;
		}
	}
	else
	{
		op = " < ";
		if ((*cmd)[*i + 1] == '<')
		{
			op = " << ";
			(*i)++;
		}
	}
	ft_cut_string(str, cmd, i, op);
}
