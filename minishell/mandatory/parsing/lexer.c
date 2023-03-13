/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:34:19 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:53 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init(t_token tok[], int *i, int *in_quote, int *in_cmd)
{
	*i = -1;
	*in_quote = 0;
	if (in_cmd != NULL)
		*in_cmd = 0;
	tok[0].value = ft_strdup("");
	tok[1].value = ft_strdup("");
	tok[0].t_in_q = 0;
	tok[1].t_in_q = 0;
	ft_newcmd(NULL, 1);
}

int	ft_update_lexer(int *index, int *in_quote, t_token *n_token, char *cmd)
{
	static char	last_op = '\0';

	if (last_op == '\0')
	{
		last_op = cmd[*index];
		*in_quote = 1;
		n_token->t_in_q = 1;
	}
	else if (*in_quote > 0 && last_op == cmd[*index])
	{
		*in_quote = 0;
		last_op = '\0';
	}
	return (0);
}

int	ft_check_quotes(char *cmd)
{
	int		i;
	int		in_quote;

	i = -1;
	in_quote = 0;
	while (cmd[++i])
	{
		if (!in_quote && (cmd[i] == '"' || cmd[i] == "'"[0]))
		{
			in_quote = 1;
			if (cmd[i] == '"')
				in_quote = 2;
		}
		else if (in_quote && (cmd[i] == '"' || cmd[i] == "'"[0]))
			if ((cmd[i] == '"' && in_quote == 2)
				|| (cmd[i] == "'"[0] && in_quote == 1))
				in_quote = 0;
	}
	return (in_quote);
}

void	ft_up_quote(char *cmd, int *i, int *in_quote)
{
	static char	last_op = '\0';

	while (cmd[*i] == ' ')
		(*i)++;
	while (cmd[*i] == "'"[0] || cmd[*i] == '"')
	{
		if (last_op == '\0')
		{
			last_op = cmd[*i];
			*in_quote = 1;
		}
		else if (last_op == cmd[*i])
		{
			last_op = '\0';
			*in_quote = 0;
		}
		(*i)++ ;
	}
}

int	ft_lexer(char *cmd)
{
	int		i;
	t_token	tok[2];
	int		in_quote;
	int		check;

	ft_init(tok, &i, &in_quote, NULL);
	if (ft_check_quotes(cmd))
		return (free(tok[0].value), free(tok[1].value), -1);
	while (cmd[++i])
	{
		ft_up_quote(cmd, &i, &in_quote);
		if (!ftv(cmd, i, in_quote))
			return (free(tok[0].value), free(tok[1].value), -1);
		check = ft_check(tok, cmd, &in_quote, &i);
		if (!check || check == -1)
			return (free(tok[0].value), free(tok[1].value), check);
		else if (check == 1)
			continue ;
		ft_join(&tok[1], cmd, i);
		i = i + ((ft_strlen(cmd) - 1 - i) * (i >= (int) ft_strlen(cmd)));
	}
	if (ft_cmp_tok(&tok[0], &tok[1], ft_strlen(cmd) - i, cmd) || !ftv(0, 0, 0))
		return (free(tok[0].value), free(tok[1].value), -1);
	return (free(tok[0].value), free(tok[1].value), 0);
}
