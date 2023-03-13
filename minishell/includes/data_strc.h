/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_strc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:45 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/10 21:20:57 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRC_H
# define DATA_STRC_H

enum e_inoutfile_type
{
	INFILE = 1,
	OUTFILE = 2
};

enum e_env_flags
{
	SHOWN,
	HIDDEN
};

enum e_shlvl_enums
{
	SHLVL_INCR,
	SHLVL0,
	SHLVL1
};

typedef struct s_wildnodes
{
	char				*data;
	struct s_wildnodes	*next;
}	t_wildnodes;

typedef struct s_heredocs
{
	char				*heredoc_name;
	char				*delimiter;
	int					in_q;
	struct s_heredocs	*next;
}	t_heredocs;
//first, create a function that generates a heredoc name
//based on the ones that exist already (using F_OK as access mode)

//and othmane will always put the returned string from generate_heredoc_name
//into the heredoc_name attribute of the node of t_heredocs type

//and then, I will just open and write to that file, and then
//subsequently read from it when 

typedef struct s_inoutfiles
{
	char				*inoutfile_name;
	int					type;
	int					flag;
	struct s_inoutfiles	*next;
}	t_inoutfiles;

typedef struct s_cmds
{
	int				num_cmd;
	char			*cmd;
	char			**args;
	int				args_len;
	t_inoutfiles	*inoutfiles;
	t_heredocs		*heredocs;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_seer
{
	int				in;
	int				out;
	int				check_sig;
	int				**fd;
	int				num_pipes;
	int				last_pid;
	unsigned char	exit_num;
	char			*pwd;
	t_cmds			*cmds;
}	t_seer;

typedef struct s_envnode
{
	int					index;
	char				*name;
	char				*value;
	int					flag;
	struct s_envnode	*next;
}	t_envnode;

typedef struct s_fd_guide
{
	int	index;
	int	end;
}	t_fd_guide;

typedef struct s_global
{
	t_envnode	*environment;
	int			in_read_line;
}	t_global;

extern t_global		g_global;
t_envnode			*get_environment(char *envp[]);
t_envnode			*get_node_if_exists(char *name);
int					get_env_size(void);
void				free_bins(char **bins);
char				*expand_to_value(char *name, t_seer *seer);
char				*generate_heredoc_name(void);
void				index_export(void);
t_cmds				*new_cmd(int num_cmd, char *cmd);
t_inoutfiles		*new_inoutfile(char *inoutfile_name, int type, int flag);
void				append_inoutfile(t_inoutfiles **io_f, t_inoutfiles *n_io);
void				process_inoutfile(t_inoutfiles *inoutfile, t_seer *seer);
void				append_heredoc(int *in_cmd, t_cmds **cmds,
						t_heredocs **hdc, t_heredocs *nhdc);
t_heredocs			*new_heredoc(char *heredoc_name, char *delimiter);
unsigned char		execute_cmds(t_seer *seer);
unsigned char		execute_single(t_cmds *cmds, t_seer *seer);
void				close_pipes(t_seer *seer, t_fd_guide *pipe1,
						t_fd_guide *pipe2);
void				garbage_collector(t_seer *seer);
void				garbage_collector_v2(t_seer *seer);
void				init_seer(t_seer *seer);
void				init_all(t_seer **seer, char *envp[]);
void				init_in_out_seer(t_cmds *cmds, t_seer *seer);
int					ft_spaces_only(char *line);
void				initialize_hardcoded_paths(t_seer *seer);
char				*ft_trim_asterisks(char *arg);
void				ft_init_begin_end(char *arg, int *begin, int *end);
void				parse_and_execute(char *line, t_seer *seer);
void				shell_loop(t_seer *seer);
void				interrupt_handler(int sig);
void				quit_handler(int sig);
char				*get_wildcard_string(char *arg, t_seer *seer);
#endif
