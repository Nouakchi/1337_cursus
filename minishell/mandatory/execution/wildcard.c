/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:57 by samini            #+#    #+#             */
/*   Updated: 2023/03/11 01:24:02 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_wildnodes	*ft_construct_wildnodes(struct dirent *direntt, DIR *dir)
{
	t_wildnodes	*nodes;
	t_wildnodes	*temp;

	direntt = readdir(dir);
	if (!direntt)
		return (NULL);
	nodes = ft_calloc(1, sizeof(t_wildnodes));
	if (!nodes)
		return (ft_perror(ERR_PROMPT, "CALLOC"), NULL);
	nodes->data = ft_strdup(direntt->d_name);
	temp = nodes;
	direntt = readdir(dir);
	while (direntt)
	{
		temp->next = ft_calloc(1, sizeof(t_wildnodes));
		if (!temp)
			return (ft_perror(ERR_PROMPT, "CALLOC"), NULL);
		temp->next->data = ft_strdup(direntt->d_name);
		temp = temp->next;
		direntt = readdir(dir);
	}
	return (nodes);
}

int	ft_matches_pattern(char *pattern, char *data)
{
	if (!*pattern && !*data)
		return (1);
	if (*pattern == '*')
		while (*(pattern + 1) == '*')
			pattern++;
	if (*pattern == '*' && *(pattern + 1) && !*data)
		return (0);
	if (*pattern == '*' && *pattern == *data)
		return (ft_matches_pattern(pattern, data + 1));
	if (*pattern == *data)
		return (ft_matches_pattern(pattern + 1, data + 1));
	if (*pattern == '*')
		return (ft_matches_pattern(pattern + 1, data)
			|| ft_matches_pattern(pattern, data + 1));
	return (0);
}

char	*ft_append_wildcards(char *arg, t_wildnodes *nodes)
{
	char		*string;
	char		*join;
	t_wildnodes	*temp;

	string = ft_strdup("");
	temp = nodes;
	while (temp)
	{
		fprintf(stderr, "pattern: %s -- data: %s\n", arg, temp->data);
		if (ft_matches_pattern(arg, temp->data))
		{
			fprintf(stderr, "They match\n");
			join = ft_strjoin(string, " ");
			free(string);
			string = ft_strjoin(join, temp->data);
			free(join);
		}
		temp = temp->next;
	}
	return (string);
}

char	*ft_construct_string(struct dirent *direntt, DIR *dir, char *arg)
{
	char		*temp;
	char		*string;
	t_wildnodes	*nodes;

	temp = ft_trim_asterisks(arg);
	nodes = ft_construct_wildnodes(direntt, dir);
	string = ft_append_wildcards(temp, nodes);
	if (string && ft_strcmp(string, "") == 0)
		return (free(string), ft_strdup(arg));
	return (string);
}

char	*test_wild(char *arg, t_seer *seer)
{
	char			*result;
	DIR				*dir;
	struct dirent	*direntt;

	(void)seer;
	dir = opendir(".");
	if (!dir)
		return (ft_perror(ERR_PROMPT, "opendir"), NULL);
	direntt = NULL;
	result = ft_construct_string(direntt, dir, arg);
	closedir(dir);
	return (result);
}
