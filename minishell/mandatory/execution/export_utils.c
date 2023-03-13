/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:20 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:36 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_env_size(void)
{
	t_envnode	*temp;
	int			i;

	temp = g_global.environment;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_write_envnode(t_envnode *temp, t_seer *seer)
{
	write(seer->out, "declare -x ", 11);
	write(seer->out, temp->name, ft_strlen(temp->name));
	if (temp->value)
	{
		write(seer->out, "=\"", 2);
		write(seer->out, temp->value, ft_strlen(temp->value));
		write(seer->out, "\"\n", 2);
	}
	else
		write(seer->out, "\n", 1);
}

int	print_ordered_env(t_seer *seer)
{
	t_envnode	*temp;
	int			i;
	int			size;

	i = 0;
	size = get_env_size();
	while (i < size)
	{
		temp = g_global.environment;
		while (temp && temp->index != i)
			temp = temp->next;
		if (temp->flag == HIDDEN)
		{
			i++;
			continue ;
		}
		ft_write_envnode(temp, seer);
		i++;
	}
	return (0);
}

t_envnode	*new_envnode(char *name, char *value)
{
	t_envnode	*node;

	node = ft_calloc(1, sizeof(t_envnode));
	if (!node)
		return (NULL);
	node->name = name;
	node->value = value;
	node->index = 0;
	node->flag = SHOWN;
	node->next = NULL;
	return (node);
}

t_envnode	*get_node_if_exists(char *name)
{
	t_envnode	*temp;

	temp = g_global.environment;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
