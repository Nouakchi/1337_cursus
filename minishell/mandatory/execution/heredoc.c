/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:00:44 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 01:23:46 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	close(0);
}

void	ft_init_hdc(char *heredoc_name, char **line, char **delimiter, int *fd)
{
	*line = NULL;
	*delimiter = ft_strjoin(*delimiter, "\n");
	signal(SIGINT, sigint_handler);
	*fd = open(heredoc_name, O_CREAT | O_WRONLY, 0666);
}

int	ft_check_tty(char *delimiter, char *line, t_seer *seer)
{
	if (ttyname(0) == 0)
	{
		if (open(ttyname(1), O_RDONLY) == -1)
			return (free(delimiter), free(line), perror("opened tty"), 1);
		seer->check_sig = 1;
	}
	return (0);
}

int	ft_read_input_heredoc(char **line, char *delimiter, t_seer *seer, int in_q)
{
	char	*tmp;

	tmp = readline(HEREDOC_PROMPT);
	if (ft_check_tty(delimiter, *line, seer))
		return (1);
	if (!tmp)
		return (free(delimiter), free(*line), 1);
	tmp = ft_join_v3(tmp, ft_strdup("\n"));
	if (!in_q)
		*line = ft_check_env(tmp, seer);
	else
		*line = ft_strdup(tmp);
	free(tmp);
	if (!delimiter || (tmp && !*line))
		return (free(delimiter), free(line), perror(ERR_PROMPT), 1);
	return (0);
}

void	heredoc(char *heredoc_name, char *delimiter, int in_q, t_seer *seer)
{
	char	*tmp;
	char	*line;
	int		fd;

	seer->check_sig = 0;
	ft_init_hdc(heredoc_name, &line, &delimiter, &fd);
	if (ft_read_input_heredoc(&line, delimiter, seer, in_q))
		return ;
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		write(fd, line, ft_strlen(line));
		tmp = readline(HEREDOC_PROMPT);
		if (ft_check_tty(delimiter, line, seer))
			return ;
		if (!tmp)
			return (free(delimiter), free(line));
		free(line);
		tmp = ft_join_v3(tmp, ft_strdup("\n"));
		if (!in_q)
			line = ft_check_env(tmp, seer);
		else
			line = ft_strdup(tmp);
		free(tmp);
	}
	return (close(fd), free(delimiter), free(line));
}
