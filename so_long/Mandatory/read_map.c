/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:21:24 by onouakch          #+#    #+#             */
/*   Updated: 2022/11/29 21:21:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *map_path)
{
	int		fd;
	char	*line;
	char	*map_container;
	char	**map;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_container = malloc(1);
	map_container[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_container = ft_strjoin(&map_container, &line);
		free(line);
	}
	map = ft_split(map_container, '\n');
	free(map_container);
	close(fd);
	return (map);
}
