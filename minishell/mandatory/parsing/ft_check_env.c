/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:46 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:23:03 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_init(int *i, char **res, char **signed_tok)
{
	*i = -1;
	*res = ft_strdup("");
	*signed_tok = ft_strdup("");
}

char	*ft_join_v3(char *str1, char *str2)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (res);
}

void	ft_free_signed_tok(char *token, char **signed_tok)
{
	if (!ft_strchr(token, '$') || !ft_strcmp(*signed_tok, ""))
		free(*signed_tok);
}

void	ft_expand(char *token, char **signed_tok, t_seer *seer, int *j)
{
	char	*tmp;

	if (ft_isdigit(token[*j + 1]) || token[*j + 1] == '?')
	{
		*signed_tok = ft_join_v3(*signed_tok, ft_substr(token, *j + 1, 1));
		*j += 2;
	}
	else
	{
		if (token[*j + 1] == '$' || token[*j + 1] == '_')
			j += 2;
		else
			while (token[++(*j)] && (ft_isalnum(token[*j]) || token[*j] == '_'))
				*signed_tok = ft_join_v3(*signed_tok, ft_substr(token, *j, 1));
	}
	tmp = *signed_tok;
	*signed_tok = expand_to_value(*signed_tok, seer);
	free(tmp);
}

char	*ft_check_env(char *token, t_seer *seer)
{
	int		i;
	int		j;
	char	*signed_token;
	char	*res;

	ft_env_init(&i, &res, &signed_token);
	while (token[++i])
	{
		if (token[i] == '$')
		{
			j = i;
			if (token[j + 1] == '\n')
				return (res = ft_join_v3(res, ft_strdup("$\n"))
					, ft_free_signed_tok(token, &signed_token), res);
			ft_expand(token, &signed_token, seer, &j);
			res = ft_join_v3(res, signed_token);
			signed_token = ft_strdup("");
			i = j - 1;
		}
		else
			res = ft_join_v3(res, ft_substr(token, i, 1));
	}
	return (ft_free_signed_tok(token, &signed_token), res);
}
