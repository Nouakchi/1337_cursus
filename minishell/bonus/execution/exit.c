/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:52:46 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:02 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_has_an(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_numeric_arg_check(char **args, t_seer *seer)
{
	char	*first;
	char	*second;

	if (ft_has_an(args[0]) || check_longlong(args[0]) == SHLVL1)
	{
		first = ft_strjoin(ERR_PROMPT, "exit: ");
		second = ft_strjoin(first, args[0]);
		free(first);
		first = ft_strjoin(second, ": numeric argument required\n");
		write(2, first, ft_strlen(first));
		free(first);
		seer->exit_num = 255;
		exit(255);
	}
}

int	exitt(char **args, t_seer *seer)
{
	char			*first;

	seer->exit_num = 0;
	if (seer->num_pipes == 0 && seer->out == 1)
		write(seer->out, "exit\n", 5);
	if (!args[0])
		exit(0);
	ft_numeric_arg_check(args, seer);
	if (args[1])
	{
		seer->exit_num = 1;
		first = ft_strjoin(ERR_PROMPT, "exit: too many arguments\n");
		write(2, first, ft_strlen(first));
		free(first);
		return (1);
	}
	seer->exit_num = ft_atoi(args[0]);
	exit(seer->exit_num);
}
