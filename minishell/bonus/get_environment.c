/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:05:16 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:37 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_to_value(char *name, t_seer *seer)
{
	t_envnode	*envnode;

	if (ft_strcmp("?", name) == 0)
		return (ft_itoa(seer->exit_num));
	if (ft_strcmp("~", name) == 0)
		name = "$~";
	envnode = get_node_if_exists(name);
	if (!envnode || !envnode->value)
		return (ft_strdup(""));
	return (ft_strdup(envnode->value));
}
