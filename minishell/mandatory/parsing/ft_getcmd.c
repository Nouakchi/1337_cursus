/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:41:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:22:49 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../includes/minishell.h"

void	ft_getcmd(int *in_cmd, t_token tok[], t_cmds **cmds, char *c)
{
	if (ft_strcmp(tok[1].value, "<") && ft_strcmp(tok[1].value, ">")
		&& ft_strcmp(tok[1].value, "<<") && ft_strcmp(tok[1].value, ">>"))
	{
		if (!ft_strcmp(tok[0].value, "<<"))
			ft_append_herdoc(in_cmd, cmds, tok, c[0]);
		else if (!ft_strcmp(tok[0].value, "<") || !ft_strcmp(tok[0].value, ">")
			|| !ft_strcmp(tok[0].value, ">>"))
			ft_add_inoutfile(in_cmd, cmds, tok);
		else
			ft_append_cmds(in_cmd, tok, cmds);
	}
	ft_go_next(tok);
	if (c[1] == '|')
		*in_cmd = 0;
}
