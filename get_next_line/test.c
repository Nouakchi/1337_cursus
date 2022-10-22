#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buff;
	static size_t 	check = -1;
	static char *reserve = "";
	char *res;

	while (check != 0 && ft_strchr(buff, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		check = read(fd, buff, BUFFER_SIZE);
		buff[check] = '\0';
		reserve = ft_strjoin(reserve, buff);
	}
	if (ft_strchr(reserve, '\n') != NULL)
	{
		res = ft_truncate(reserve);
		while (*reserve && *reserve != '\n')
			reserve++;
		reserve++;
	}
	else
	{
		res = reserve;
		reserve = "";
	}
	return (res);
}

int main()
{
	int fd = open("get_next_line.h", O_RDWR);
	// get_next_line(fd);
	char *s = get_next_line(fd);
	printf("%s", get_next_line(fd));
	while (*s)
	{
		printf("%s", get_next_line(fd));
		s = get_next_line(fd);
	}
}