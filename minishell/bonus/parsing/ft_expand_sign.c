/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:02:59 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:25:17 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_split_token(t_args *args, int *in_cmd, char *tmp)
{
	char	**arr;
	int		i;
	t_cmds	*last;

	arr = ft_split(tmp, ' ');
	i = 0;
	if (ft_lastcmd(args->cmds) == NULL)
	{
		ft_cmdadd_back(args->cmds, ft_newcmd(arr[i], 0));
		last = ft_lastcmd(args->cmds);
		last->args = ft_arr_additem(last->args,
				arr[i++], ft_lastcmd(args->cmds)->args_len++);
		*in_cmd = 1;
	}
	while (arr[i + 1])
	{
		last = ft_lastcmd(args->cmds);
		last->args = ft_arr_additem(ft_lastcmd(args->cmds)->args, arr[i],
				ft_lastcmd(args->cmds)->args_len++);
		i++;
	}
	free(args->signed_token);
	return (free(args->res), args->res = ft_strdup(arr[i]), free_bins(arr));
}

void	ft_split_signed_tokn(t_args *args, int *in_cmd, t_seer *seer, char *tmp)
{
	if (ft_strcmp(args->signed_token, ""))
		tmp = expand_to_value(args->signed_token, seer);
	else
		tmp = ft_strdup("$");
	if (args->in_quote == 0 && ft_strchr(tmp, ' '))
	{
		ft_split_token(args, in_cmd, tmp);
		free(tmp);
	}
	else
	{
		args->tmp = args->signed_token;
		if (ft_strcmp(args->signed_token, ""))
			args->signed_token = expand_to_value(args->signed_token, seer);
		else
			args->signed_token = ft_strdup("$");
		free(args->tmp);
		args->tmp = args->res;
		args->res = ft_strjoin(args->res, args->signed_token);
		return (free(tmp), free(args->tmp), free(args->signed_token));
	}
}

void	ft_expand_sign(t_vars *vars, t_seer *seer, t_args *args, int *i)
{
	int		j;
	char	*tmp;

	tmp = NULL;
	if ((*vars->token)[*i] == '$' && args->in_quote != 1)
	{
		j = *i;
		args->signed_token = ft_strdup("");
		ft_str_to_env(vars->token, args, &j);
		ft_split_signed_tokn(args, vars->in_cmd, seer, tmp);
		*i = j - 1;
		free(tmp);
	}
	else
	{
		args->tmp = args->res;
		args->tmp2 = ft_substr((*vars->token), *i, 1);
		args->res = ft_strjoin(args->res, args->tmp2);
		free(args->tmp);
		free(args->tmp2);
	}
}
