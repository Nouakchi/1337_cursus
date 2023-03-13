/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:51:14 by samini            #+#    #+#             */
/*   Updated: 2023/03/10 22:46:52 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int					echo(char **args, t_seer *seer);
int					cd(char **args, t_seer *seer);
int					pwd(char **args, t_seer *seer);
int					export(char **args, t_seer *seer);
int					unset(char **args, t_seer *seer);
int					env(char **args, t_seer *seer);
int					exitt(char **args, t_seer *seer);

void				ft_dup2(t_cmds *cmds, t_seer *seer);
void				process_heredocs_pipeline(t_seer *seer);
void				process_heredocs(t_cmds *cmds, t_seer *seer);
int					is_builtin(char *cmd);
unsigned char		ft_exec_cmd(t_cmds *cmds, t_seer *seer);
unsigned char		process_infile_safe(t_inoutfiles *inoutfile, t_seer *seer);
unsigned char		process_outfile_safe(t_inoutfiles *inoutfile, t_seer *seer);
unsigned char		process_inoutfile_safe(t_inoutfiles *io_file, t_seer *seer);
void				process_infiles(t_cmds *cmds, t_seer *seer);
void				process_outfiles(t_cmds *cmds, t_seer *seer);
void				heredoc(char *hdc_name, char *del, int in_q, t_seer *seer);
void				close_pipes(t_seer *seer, t_fd_guide *pp1, t_fd_guide *pp2);
char				*get_command(t_cmds *cmds, t_seer *seer);
void				ft_get_command_check(char *command);
char				**get_env_arr(void);

enum e_shlvl_enums	check_longlong(char *str);
int					check_valid(char *name);
enum e_shlvl_enums	check_shlvl_change(char *str);
int					is_builtin(char *cmd);
unsigned char		execute_builtin(t_cmds *cmds, t_seer *seer);
void				invalid_name_export(char *identifier);
t_envnode			*new_envnode(char *name, char *value);
int					print_ordered_env(t_seer *seer);
int					get_env_size(void);
void				ft_write_envnode(t_envnode *temp, t_seer *seer);
t_envnode			*get_node_if_exists(char *name);
char				*ft_getnodevalue(char *value);
void				free_wildnodes(t_wildnodes *nodes);
void				assign_val(t_envnode *node, char *value);
char				*get_name_export(char *name);
void				update_old_pwd(t_seer *seer);
unsigned char		cd_home(t_seer *seer);
unsigned int		cd_swap(t_seer *seer);
void				ft_join_dot_pwd(char **args, t_seer *seer);
void				init_oldpwd(t_seer *seer);
void				init_path(t_seer *seer);
void				init_pwd(t_seer *seer);
void				export_shlvl(int level, t_seer *seer);
void				init_shlvl(t_seer *seer);

#endif
