/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:03:43 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:25:51 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_change_dir(char **args, t_seer *seer)
{
	if (!args[0])
	{
		if (cd_home(seer))
			return (1);
	}
	else if (ft_strcmp(args[0], "-") == 0)
	{
		if (cd_swap(seer))
			return (1);
	}
	else if (chdir(args[0]) != 0)
		return (ft_perror("minishell: cd: ", args[0]), errno);
	return (0);
}

void	ft_first_check(char *first, t_seer *seer)
{
	if (first)
	{
		free(seer->pwd);
		seer->pwd = first;
	}
	else
		ft_perror(ERR_PROMPT, "cd");
}

int	cd(char **args, t_seer *seer)
{
	int			result;
	char		*first;
	t_envnode	*temp;

	if (!seer->pwd)
		return (seer->pwd = ft_strdup("."), ft_putstr_fd(ERRRETDIR, 2), 0);
	ft_join_dot_pwd(args, seer);
	result = ft_change_dir(args, seer);
	if (result)
		return (result);
	update_old_pwd(seer);
	first = getcwd(NULL, 0);
	ft_first_check(first, seer);
	if (seer->pwd)
	{
		temp = get_node_if_exists("PWD");
		if (temp)
		{
			free(temp->value);
			temp->value = ft_strdup(seer->pwd);
		}
	}
	return (0);
}
