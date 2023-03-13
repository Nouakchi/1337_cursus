/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:51:54 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:22:01 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset_underscore(t_seer *seer)
{
	char	*x[2];

	x[0] = "_";
	x[1] = NULL;
	unset(x, seer);
}

void	parse_and_execute(char *line, t_seer *seer)
{
	char	*tmp;

	if (ft_lexer(line) == -1)
	{
		ft_putstr_fd("syntax error\n", 2);
		free(line);
		return ;
	}
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	seer->cmds = ft_parser(ft_strjoin(line, " "), seer);
	process_heredocs_pipeline(seer);
	free(line);
	if (seer->check_sig == 1)
	{
		seer->check_sig = 0;
		garbage_collector_v2(seer);
		return ;
	}
	execute_cmds(seer);
	garbage_collector(seer);
	ft_unset_underscore(seer);
}

void	shell_loop(t_seer *seer)
{
	char	*line;

	while (1)
	{
		g_global.in_read_line = 1;
		line = readline(PROMPT);
		g_global.in_read_line = 0;
		if (!line)
			line = ft_strdup("exit");
		if (ttyname(0) == 0)
		{
			if (open(ttyname(1), O_RDONLY) == -1)
				return (free(line), ft_perror(ERR_PROMPT, "opentty"));
			continue ;
		}
		if (ft_spaces_only(line))
		{
			free(line);
			continue ;
		}
		else
			add_history(line);
		parse_and_execute(line, seer);
	}
}
