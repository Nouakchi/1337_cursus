#include "so_long_bonus.h"

char **ft_read_map(char *map_path)
{
    int fd;
    char *line;
    char *map_container;
    char **map;
    
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    map_container = malloc(1);
    map_container[0] = '\0';
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        map_container = ft_strjoin(&map_container, &line);
        free(line);
    }
    map = ft_split(map_container, '\n');
    free(map_container);
    close(fd);
    return (map);
}