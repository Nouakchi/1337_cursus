/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:58:41 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:56 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isop(char *op)
{
	if (!ft_strcmp(op, "<") || !ft_strcmp(op, "<<")
		|| !ft_strcmp(op, ">") || !ft_strcmp(op, ">>")
		|| !ft_strcmp(op, "|"))
		return (1);
	return (0);
}

int	ft_istok(char *op)
{
	if (!ft_strcmp(op, "<") || !ft_strcmp(op, "<<")
		|| !ft_strcmp(op, ">") || !ft_strcmp(op, ">>"))
		return (1);
	return (0);
}

int	ft_cmp_tok(t_token *tok, t_token *n_tok, int index, char *cmd)
{
	char	*tmp;

	if (ft_istok(tok->value)
		&& (n_tok->value[0] == '<' || n_tok->value[0] == '>'))
		return (-1);
	if (ft_strcmp(tok->value, "|") && (ft_isop(tok->value)
			&& ft_isop(n_tok->value)
			&& tok->t_in_q == 0 && n_tok->t_in_q == 0))
		return (-1);
	if ((ft_isop(n_tok->value) && !index) || (!ft_strcmp(n_tok->value, "|")
			&& index + 1 == (int)ft_strlen(cmd)))
		return (-1);
	if (ft_strcmp(n_tok->value, ""))
	{
		tok->t_in_q = n_tok->t_in_q;
		tmp = tok->value;
		tok->value = n_tok->value;
		free(tmp);
		n_tok->value = ft_strdup("");
		n_tok->t_in_q = 0;
	}
	return (0);
}

int	ftv(char *tok, int i, int in_quote)
{
	static int	found_op = 0;

	if (!tok)
		return (!found_op);
	if (!in_quote)
	{
		if ((found_op == 1 || found_op == 2)
			&& (tok[i] != '>' && tok[i] != '<' && tok[i] != '|'))
			found_op = 0;
		if (tok[i] == '>' || tok[i] == '<' || tok[i] == '|')
			found_op++;
		if (found_op == 2 && tok[i] == '|')
			return (0);
		if (found_op == 3 || (found_op == 2 && tok[i] != tok [i - 1]))
			if (tok[i] == '|')
				return (found_op = 0, 0);
	}
	return (1);
}

int	ft_check(t_token *tok, char *command, int *in_quote, int *i)
{
	if (command[*i] == ' ' && !(*in_quote))
	{
		if (!ft_strcmp(tok[1].value, "#"))
			return (0);
		if (ft_cmp_tok(&tok[0], &tok[1], ft_strlen(command) - *i, command))
			return (-1);
		return (1);
	}
	return (2);
}
