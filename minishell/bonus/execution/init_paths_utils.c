/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:27:49 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:26:45 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_oldpwd(t_seer *seer)
{
	char		**arr;
	t_envnode	*envnode;

	envnode = get_node_if_exists("OLDPWD");
	if (envnode)
	{
		free(envnode->value);
		envnode->value = NULL;
	}
	else
	{
		arr = ft_split("OLDPWD", ' ');
		if (!arr)
			return (ft_perror(ERR_PROMPT, "OLDPWD"));
		export(arr, seer);
		free_bins(arr);
	}
}

void	init_path(t_seer *seer)
{
	char		**temp;

	if (!get_node_if_exists("PATH"))
	{
		temp = ft_split(HARDPATH, ' ');
		if (!temp)
			return (ft_perror(ERR_PROMPT, "PATH"));
		export(temp, seer);
		get_node_if_exists("PATH")->flag = HIDDEN;
		free_bins(temp);
	}
}

void	init_pwd(t_seer *seer)
{
	char	*currdir;
	char	**temp;
	char	*join;

	currdir = getcwd(NULL, 0);
	if (!currdir)
		return (ft_perror(ERR_PROMPT, "getcwd() failed"));
	join = ft_strjoin("PWD=", currdir);
	free(currdir);
	if (!join)
		return (ft_perror(ERR_PROMPT, "PWD"));
	temp = ft_split(join, ' ');
	free(join);
	if (!temp)
		return (ft_perror(ERR_PROMPT, "SPLIT"));
	export(temp, seer);
	free_bins(temp);
}

void	export_shlvl(int level, t_seer *seer)
{
	char	**temp;
	char	*join;
	char	*slevel;

	slevel = ft_itoa(level);
	if (!slevel)
		return (ft_perror(ERR_PROMPT, "ITOA"));
	join = ft_strjoin("SHLVL=", slevel);
	free(slevel);
	if (!join)
		return (ft_perror(ERR_PROMPT, "STRJOIN"));
	temp = ft_split(join, ' ');
	free(join);
	if (!temp)
		return (ft_perror(ERR_PROMPT, "SHLVL"));
	export(temp, seer);
	free_bins(temp);
}

void	init_shlvl(t_seer *seer)
{
	enum e_shlvl_enums	shlvl_enum;
	int					level;
	char				*slevel;

	if (!get_node_if_exists("SHLVL"))
		export_shlvl(1, seer);
	else
	{
		slevel = expand_to_value("SHLVL", seer);
		if (!slevel)
			return (ft_perror(ERR_PROMPT, "SHLVL"));
		shlvl_enum = check_shlvl_change(slevel);
		level = ft_atoi(slevel) + 1;
		if (shlvl_enum == SHLVL0)
			level = 0;
		else if (shlvl_enum == SHLVL1)
			level = 1;
		if (level > 999)
		{
			ft_putstr_fd(SHLVL_WARNING, 2);
			level = 1;
		}
		free(slevel);
		export_shlvl(level, seer);
	}
}
