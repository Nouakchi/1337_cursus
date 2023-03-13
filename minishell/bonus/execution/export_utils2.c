/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:51:46 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:12 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_name_export(char *name)
{
	char	*new_name;
	int		i;
	int		j;

	i = 0;
	while (name[i] && !(name[i] == '='
			|| (name[i] == '+' && name[i + 1] == '=')))
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

int	check_valid(char *name)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(*name) || *name == '_'))
		return (0);
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	invalid_name_export(char *identifier)
{
	char	*first;
	char	*second;

	first = ft_strjoin(ERR_PROMPT, "export: `");
	second = ft_strjoin(first, identifier);
	free(first);
	first = ft_strjoin(second, "': not a valid identifier\n");
	free(second);
	write(2, first, ft_strlen(first));
	free(first);
}

void	assign_val(t_envnode *node, char *value)
{
	char	*temp;

	if (!*value)
		free(value);
	else if (*value == '=')
	{
		temp = node->value;
		node->value = ft_strdup(value + 1);
		free(temp);
		free(value);
	}
	else if (*value == '+' && value[1] == '=')
	{
		temp = node->value;
		if (!node->value)
			node->value = "";
		node->value = ft_strjoin(node->value, value + 2);
		free(temp);
		free(value);
	}
}

char	*ft_getnodevalue(char *value)
{
	char	*new_value;

	new_value = NULL;
	if (value)
	{
		if (!*value)
			free(value);
		else if (value[0] == '=')
		{
			new_value = ft_strdup(value + 1);
			free(value);
		}
		else if (value[0] == '+' && value[1] == '=')
		{
			new_value = ft_strdup(value + 2);
			free(value);
		}
	}
	return (new_value);
}
