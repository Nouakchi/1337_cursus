/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environment_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:04:00 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:21:53 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_name(char *name)
{
	char	*new_name;
	int		i;
	int		j;

	i = 0;
	while (name[i] && name[i] != '=')
		i++;
	new_name = malloc(sizeof(char) * (i + 1));
	if (!new_name)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_name[j] = name[j];
		j++;
	}
	new_name[j] = '\0';
	return (new_name);
}

t_envnode	*get_envnode(char *envp[], int i)
{
	t_envnode	*head;
	char		*name;

	head = ft_calloc(1, sizeof(t_envnode));
	if (!head)
		return (NULL);
	name = get_name(envp[i]);
	if (!name)
		return (NULL);
	head->name = name;
	head->value = ft_strdup(envp[i] + ft_strlen(head->name) + 1);
	head->index = 0;
	head->flag = SHOWN;
	head->next = NULL;
	return (head);
}

t_envnode	*get_environment(char *envp[])
{
	t_envnode	*head;
	t_envnode	*temp;
	int			i;

	head = NULL;
	i = 0;
	while (envp[i])
	{
		if (!head)
		{
			head = get_envnode(envp, i);
			if (!head)
				return (NULL);
			temp = head;
		}
		else
		{
			temp->next = get_envnode(envp, i);
			if (!temp->next)
				return (NULL);
			temp = temp->next;
		}
		i++;
	}
	return (head);
}

void	init_indexes(t_envnode *head)
{
	while (head)
	{
		head->index = 0;
		head = head->next;
	}
}

void	index_export(void)
{
	t_envnode	*head;
	t_envnode	*temp;

	head = g_global.environment;
	init_indexes(head);
	while (head)
	{
		temp = g_global.environment;
		while (temp)
		{
			if (temp == head)
			{
				temp = temp->next;
				continue ;
			}
			if (ft_strcmp(head->name, temp->name) > 0)
				head->index = head->index + 1;
			temp = temp->next;
		}
		head = head->next;
	}
}
