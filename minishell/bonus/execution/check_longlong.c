/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_longlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:57 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:25:54 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_number(char *str)
{
	char	*number;
	int		i;

	i = 0;
	if (!ft_isdigit(str[0]))
		return (NULL);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	number = ft_calloc(1, i + 1);
	if (!number)
		return (ft_perror(ERR_PROMPT, "GET_NUMBER"), NULL);
	ft_strlcpy(number, str, i + 1);
	return (number);
}

enum e_shlvl_enums	check_longlong(char *str)
{
	int		i;
	char	*number;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (SHLVL0);
	number = get_number(str + i);
	if (!number)
		return (SHLVL1);
	if (ft_strlen(number) == ft_strlen(MAXLONGLONG)
		&& ft_strcmp(str, MAXLONGLONG) > 0)
		return (free(number), SHLVL1);
	if (ft_strlen(number) > ft_strlen(MAXLONGLONG))
		return (free(number), SHLVL1);
	if (ft_strlen(number) == ft_strlen(MAXINT) && ft_strcmp(str, MAXINT) >= 0)
		return (free(number), SHLVL0);
	return (free(number), SHLVL_INCR);
}

enum e_shlvl_enums	check_shlvl_change(char *str)
{
	enum e_shlvl_enums	result;
	int					i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			break ;
		i++;
	}
	while (str[i])
	{
		if (str[i] != ' ')
			return (SHLVL1);
		i++;
	}
	result = check_longlong(str);
	return (result);
}
