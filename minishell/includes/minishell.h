/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:29:00 by samini            #+#    #+#             */
/*   Updated: 2023/03/10 17:55:44 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# define PROMPT "minishell$ "
# define ERR_PROMPT "minishell: "
# define HEREDOC_NAME "/tmp/.heredoc"
# define HEREDOC_PROMPT "> "
# define HARDPATH "PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."
# define MAXLONGLONG "9223372036854775807"
# define MINLONGLONG "9223372036854775808"
# define MAXINT "2147483647"
# define ERRRETDIR "error retrieving current directory\n"
# define SHLVL_WARNING "minishell: warning: shell level too high,\
 resetting to 1\n"
# include "data_strc.h"
# include "../mandatory/parsing/parsing.h"
# include "../mandatory/execution/execution.h"

#endif
