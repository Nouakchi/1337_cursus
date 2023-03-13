/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:56:21 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:35 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_increment(int *num, int *offset, char *join, char *number)
{
	(*num)++;
	(*offset)++;
	free(join);
	free(number);
}

char	*generate_heredoc_name(void)
{
	static int	offset;
	char		*join;
	char		*number;
	int			num;

	num = offset++;
	number = ft_itoa(num);
	if (!number)
		return (ft_perror(ERR_PROMPT, "ITOA"), NULL);
	join = ft_strjoin(HEREDOC_NAME, number);
	if (!join)
		return (ft_perror(ERR_PROMPT, "JOIN"), NULL);
	while (access(join, F_OK) == 0)
	{
		ft_free_increment(&num, &offset, join, number);
		number = ft_itoa(num);
		if (!number)
			return (NULL);
		join = ft_strjoin(HEREDOC_NAME, number);
		if (!join)
			return (NULL);
	}
	errno = 0;
	return (free(number), join);
}
