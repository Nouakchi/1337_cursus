/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:44 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:27 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_option(char *first_arg)
{
	int	i;
	int	notn;

	if (!first_arg)
		return (0);
	if (*first_arg == '-')
	{
		i = 1;
		notn = 1;
		while (first_arg[i])
		{
			if (first_arg[i] != 'n')
				notn = 0;
			i++;
		}
		if (i == 1)
			return (0);
		return (notn);
	}
	return (0);
}

int	echo(char **args, t_seer *seer)
{
	int	i;
	int	j;
	int	option;

	i = 0;
	while (check_option(args[i]))
		i++;
	option = i;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			write(seer->out, args[i] + j, 1);
			j++;
		}
		i++;
		if (args[i])
			write(seer->out, " ", 1);
	}
	if (option == 0)
		write(seer->out, "\n", 1);
	return (0);
}
