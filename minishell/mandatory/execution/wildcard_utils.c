/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:50:57 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:03 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_begin_end(char *arg, int *begin, int *end)
{
	int	i;

	*begin = 0;
	*end = 0;
	i = 0;
	if (*arg == '*')
		*begin = 1;
	while (arg[i])
		i++;
	if (arg[i -1] == '*')
		*end = 1;
}

char	*ft_trim_asterisks(char *arg)
{
	int		begin;
	int		end;
	char	*trimmed;
	char	*join;

	ft_init_begin_end(arg, &begin, &end);
	trimmed = ft_strtrim(arg, "*");
	if (begin)
	{
		join = ft_strjoin("*", trimmed);
		free(trimmed);
		trimmed = join;
	}
	if (end)
	{
		join = ft_strjoin(trimmed, "*");
		free(trimmed);
		trimmed = join;
	}
	return (trimmed);
}
