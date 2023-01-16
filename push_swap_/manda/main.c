/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:00:10 by onouakch          #+#    #+#             */
/*   Updated: 2023/01/16 17:41:07 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ff(void)
{
	system("leaks push_swap");
}

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	int		av_len;
	int		args_len;	
	t_list	*stack_a;
	char	**args;

	atexit(ff);
	if (ac <= 1)
		return (0);
	av_len = 0;
	while (++av_len < ac)
	{
		if (ft_strchr(av[av_len], ' '))
		{
			args = ft_split(av[av_len], ' ');
			args_len = -1;
			while (args[++args_len] != NULL)
				if (!ft_lst_insert(&stack_a, args[args_len], args))
					return (exit_error(), 0);
			ft_free_args(args);
		}
		else
			if (!ft_lst_insert(&stack_a, av[av_len], NULL))
				return (exit_error(), 0);
	}
	ft_push_swap(&stack_a);
	return (0);
}
