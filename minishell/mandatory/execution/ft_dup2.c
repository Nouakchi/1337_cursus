/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:48 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:23:41 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_dup2(t_cmds *cmds, t_seer *seer)
{
	t_inoutfiles	*temp;

	init_in_out_seer(cmds, seer);
	temp = cmds->inoutfiles;
	while (temp)
	{
		process_inoutfile(temp, seer);
		temp = temp->next;
	}
	if (dup2(seer->in, 0) == -1 || dup2(seer->out, 1) == -1)
		return (perror(ERR_PROMPT), exit(errno));
	if (seer->in != 0)
		close(seer->in);
	if (seer->out != 1)
		close(seer->out);
	close_pipes(seer, NULL, NULL);
}
