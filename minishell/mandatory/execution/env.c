/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:22:16 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:29 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env(char **args, t_seer *seer)
{
	t_envnode	*temp;

	(void)args;
	temp = g_global.environment;
	while (temp)
	{
		if (temp->value)
		{
			write(seer->out, temp->name, ft_strlen(temp->name));
			write(seer->out, "=", 1);
			write(seer->out, temp->value, ft_strlen(temp->value));
			write(seer->out, "\n", 1);
		}
		temp = temp->next;
	}
	return (0);
}
