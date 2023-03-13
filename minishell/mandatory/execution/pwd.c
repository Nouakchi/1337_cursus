/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:25 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:59 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd(char **args, t_seer *seer)
{
	char	*path;

	(void)args;
	if (!seer->pwd)
		return (ft_putstr_fd(ERR_PROMPT, 2), ft_putstr_fd(ERRRETDIR, 2), 1);
	path = ft_strdup(seer->pwd);
	if (!path)
		return (ft_perror(ERR_PROMPT, "pwd"), errno);
	write(seer->out, path, ft_strlen(path));
	write(seer->out, "\n", 1);
	free(path);
	return (0);
}
