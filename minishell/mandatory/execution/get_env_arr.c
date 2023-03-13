/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:23:37 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:44 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_env_arr(void)
{
	int			i;
	char		*join;
	char		**env_arr;
	t_envnode	*temp;

	temp = g_global.environment;
	env_arr = ft_calloc(get_env_size() + 1, sizeof(char *));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (temp)
	{
		join = ft_strjoin(temp->name, "=");
		if (!join)
			return (perror(ERR_PROMPT), free_bins(env_arr), NULL);
		if (temp->value)
			env_arr[i] = ft_strjoin(join, temp->value);
		else
			env_arr[i] = ft_strdup(temp->name);
		free(join);
		if (!env_arr[i++])
			return (perror(ERR_PROMPT), free_bins(env_arr), NULL);
		temp = temp->next;
	}	
	return (env_arr);
}
