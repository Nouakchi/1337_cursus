/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:54:12 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:50 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_checker(char *cmd, int *i, int *in_quote, t_token *tok)
{
	if (cmd[*i] == '"' || cmd[*i] == "'"[0])
		ft_update_parser(i, in_quote, tok, cmd);
	if (cmd[*i] == '#' && !*in_quote)
		return (-1);
	return (0);
}

void	ft_join_v2(t_args *args)
{
	args->tmp = args->signed_token;
	args->signed_token = ft_strjoin(args->signed_token, args->tmp2);
	free(args->tmp);
	free(args->tmp2);
}

void	ft_str_to_env(char **token, t_args *args, int *j)
{
	if (ft_isdigit((*token)[*j + 1]) || (*token)[*j + 1] == '?')
	{
		args->tmp2 = ft_substr(*token, *j + 1, 1);
		ft_join_v2(args);
		*j += 2;
	}
	else
	{
		if ((*token)[*j + 1] == '$' || (*token)[*j + 1] == '_')
		{
			free(args->signed_token);
			args->signed_token = ft_strdup("$");
			(*j) += 2;
		}
		else
		{
			while ((*token)[++(*j)] && (ft_isalnum((*token)[*j])
					|| (*token)[*j] == '_'))
			{
				args->tmp2 = ft_substr(*token, *j, 1);
				ft_join_v2(args);
			}
		}
	}
}
