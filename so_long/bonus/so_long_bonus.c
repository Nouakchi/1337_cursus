#include "so_long_bonus.h"

int check_ext(char *str)
{
    int i;

    i = -1;
    while (str[++i]);
    i--;
    if (str[i] == 'r' && str[i - 1] == 'e' 
            && str[i - 2] == 'b' && str[i - 3] == '.')
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    t_play play;

    if (ac == 2)
    {
        play.map = ft_read_map(av[1]);
        if (check_ext(av[1]) && valid_map(&play))
        {
            paly_init(&play);
            start_play(&play);
            mlx_loop(play.mlx_ptr);
        }
        else
        {
			if (play.map)
				free_map(play.map);
			printf("Invalid Map\n");
			exit(1);
		}
    }
    else
    {
        printf("Invalid args\n");
        exit(1);
    }
    return (0);
}