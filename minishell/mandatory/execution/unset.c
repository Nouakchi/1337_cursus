/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:04:27 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:00 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_var_env(char *name)
{
	t_envnode	*temp;
	t_envnode	*prev;

	temp = g_global.environment;
	if (!temp)
		return ;
	if (ft_strcmp(temp->name, name) == 0)
	{
		g_global.environment = g_global.environment->next;
		free(temp->name);
		return (free(temp->value), free(temp));
	}
	prev = temp;
	temp = temp->next;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0)
		{
			prev->next = temp->next;
			free(temp->name);
			return (free(temp->value), free(temp));
		}
		prev = temp;
		temp = temp->next;
	}
}

int	unset(char **args, t_seer *seer)
{
	int	retval;
	int	i;

	(void)seer;
	if (!args[0])
		return (0);
	retval = 0;
	i = 0;
	while (args[i])
	{
		if (check_valid(args[i]))
			remove_var_env(args[i]);
		else
			retval = 0;
		i++;
	}
	index_export();
	return (retval);
}
