/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:27:31 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:06 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	append_envnode(char	*name, char *value)
{
	t_envnode	*temp;
	t_envnode	*node;
	char		*new_value;

	new_value = ft_getnodevalue(value);
	node = new_envnode(name, new_value);
	if (!g_global.environment)
	{
		g_global.environment = node;
		return ;
	}
	temp = g_global.environment;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	ft_assign_append_envnode(char **args, char *name, int i)
{
	t_envnode	*envnode;
	char		*value;

	envnode = get_node_if_exists(name);
	value = ft_strdup(args[i] + ft_strlen(name));
	if (envnode)
	{
		assign_val(envnode, value);
		free(name);
	}
	else
		append_envnode(name, value);
}

int	export(char	**args, t_seer *seer)
{
	int			ret_val;
	int			i;
	char		*name;

	ret_val = 0;
	if (!args[0])
		return (print_ordered_env(seer));
	i = -1;
	while (args[++i])
	{
		name = get_name_export(args[i]);
		if (!check_valid(name))
		{
			ret_val = 1;
			invalid_name_export(args[i]);
			free(name);
			continue ;
		}
		ft_assign_append_envnode(args, name, i);
	}
	index_export();
	return (ret_val);
}
