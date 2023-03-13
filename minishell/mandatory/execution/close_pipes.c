/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:18:24 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:21 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_pipes(t_seer *seer, t_fd_guide *pipe1, t_fd_guide *pipe2)
{
	int	index;
	int	end;

	index = 0;
	while (index < seer->num_pipes)
	{
		end = 0;
		while (end < 2)
		{
			if (pipe1 && pipe1->index == index && pipe1->end == end)
			{
				end++;
				continue ;
			}
			if (pipe2 && pipe2->index == index && pipe2->end == end)
			{
				end++;
				continue ;
			}
			close(seer->fd[index][end]);
			end++;
		}
		index++;
	}
}
