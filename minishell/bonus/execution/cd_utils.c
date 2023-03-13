/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:58:13 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:25:52 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_old_pwd(const char *pwd)
{
	char	*temp;
	int		len;

	len = ft_strlen(pwd);
	if (ft_strcmp(pwd + len - 3, "/..") == 0)
	{
		temp = malloc(sizeof(char) * (len - 2));
		if (!temp)
			return (NULL);
		ft_memcpy(temp, pwd, len - 3);
		temp[len - 3] = '\0';
		return (temp);
	}
	else if (ft_strcmp(pwd + len - 2, "/.") == 0)
	{
		temp = malloc(sizeof(char) * (len - 1));
		if (!temp)
			return (NULL);
		ft_memcpy(temp, pwd, len - 2);
		temp[len - 2] = '\0';
		return (temp);
	}
	return (ft_strdup(pwd));
}

void	update_old_pwd(t_seer *seer)
{
	t_envnode	*temp;

	temp = get_node_if_exists("OLDPWD");
	if (temp)
	{
		free(temp->value);
		temp->value = get_old_pwd(seer->pwd);
		if (!temp)
			return (ft_putstr_fd("minishell: cd: couldn't set OLDPWD", 2));
	}
}

unsigned char	cd_home(t_seer *seer)
{
	char		*first;
	char		*second;
	t_envnode	*temp;

	(void)seer;
	temp = get_node_if_exists("HOME");
	if (!temp)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	if (chdir(temp->value) != 0)
	{
		first = ft_strjoin(ERR_PROMPT, "cd: ");
		second = ft_strjoin(first, temp->value);
		free(first);
		return (perror(second), free(second), errno);
	}
	return (0);
}

unsigned int	cd_swap(t_seer *seer)
{
	char		*first;
	char		*second;
	t_envnode	*temp;

	(void)seer;
	temp = get_node_if_exists("OLDPWD");
	if (!temp)
		return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), 1);
	if (chdir(temp->value) != 0)
	{
		first = ft_strjoin(ERR_PROMPT, "cd: ");
		second = ft_strjoin(first, temp->value);
		free(first);
		return (perror(second), free(second), errno);
	}
	ft_putstr_fd(temp->value, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

void	ft_join_dot_pwd(char **args, t_seer *seer)
{
	char	*first;
	char	*second;

	if (args[0] && (ft_strcmp(args[0], ".") == 0
			|| ft_strcmp(args[0], "..") == 0))
	{
		first = ft_strjoin(seer->pwd, "/");
		second = ft_strjoin(first, args[0]);
		free(first);
		free(seer->pwd);
		seer->pwd = second;
	}
}
