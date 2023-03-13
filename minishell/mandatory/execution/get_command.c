/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:22:36 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:42 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_command_check(char *command)
{
	struct stat	data;

	stat(command, &data);
	if (S_ISDIR(data.st_mode))
	{
		ft_putstr_fd(ERR_PROMPT, 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
}

int	ft_has_slash(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			return (1);
	return (0);
}

void	free_bins(char **bins)
{
	int	i;

	i = -1;
	if (!bins)
		return ;
	while (bins[++i])
		free(bins[i]);
	free(bins);
}

char	*get_command(t_cmds *cmds, t_seer *seer)
{
	int		i;
	char	*arg;
	char	*path;
	char	**bins;
	char	*command;

	(void)seer;
	if (!cmds->cmd || ft_strcmp(cmds->cmd, "") == 0)
		exit(0);
	if (ft_has_slash(cmds->cmd))
		return (ft_strdup(cmds->cmd));
	path = expand_to_value("PATH", seer);
	bins = ft_split(path, ':');
	arg = ft_strjoin("/", cmds->cmd);
	if (!bins || !path || !arg)
		return (perror(ERR_PROMPT), exit(errno), NULL);
	i = -1;
	while (bins[++i])
	{
		command = ft_strjoin(bins[i], arg);
		if (access(command, X_OK) == 0)
			return (free_bins(bins), free(path), free(arg), command);
		free(command);
	}
	return (free_bins(bins), free(path), free(arg), NULL);
}
