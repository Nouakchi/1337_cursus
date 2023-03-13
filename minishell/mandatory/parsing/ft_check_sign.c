/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:44:43 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:45 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_quote(t_vars vars, t_args *args, t_seer *seer)
{
	char	last_op;
	int		i;

	i = -1;
	while ((*vars.token)[++i])
	{
		if (((*vars.token)[i] == "'"[0] || (*vars.token)[i] == '"')
				&& !args->in_quote)
		{
			if ((*vars.token)[i] == "'"[0])
				args->in_quote = 1;
			else
				args->in_quote = 2;
			last_op = (*vars.token)[i];
			continue ;
		}
		if (args->in_quote && (*vars.token)[i] == last_op)
		{
			args->in_quote = 0;
			last_op = '\0';
			continue ;
		}
		ft_expand_sign(&vars, seer, args, &i);
	}
}

void	ft_check_init(t_args *args, t_cmds **cmds)
{
	args->res = ft_strdup("");
	args->in_quote = 0;
	args->cmds = cmds;
}

char	*ft_check_sign(t_vars vars, t_seer *seer, t_cmds **cmds)
{
	t_args	args;

	if (!ft_strcmp(*vars.token, "$") || !ft_strcmp(*vars.token, "\"$\""))
		return (free(*vars.token), ft_strdup("$"));
	ft_check_init(&args, cmds);
	ft_update_quote(vars, &args, seer);
	return (free(*vars.token), args.res);
}

char	**ft_arr_additem(char **args, char *str, int len)
{
	char	**res;
	int		i;

	res = malloc((len + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		res[i] = ft_strdup(args[i]);
	}
	res[i] = ft_strdup(str);
	res[i + 1] = NULL;
	i = -1;
	while (++i < len)
		free(args[i]);
	free(args);
	return (res);
}
