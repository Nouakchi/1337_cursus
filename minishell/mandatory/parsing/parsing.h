/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:04:46 by onouakch          #+#    #+#             */
/*   Updated: 2023/03/11 00:46:29 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../includes/minishell.h"

typedef struct s_token
{
	int		t_in_q;
	char	*value;
}	t_token;

typedef struct s_args
{
	int		in_quote;
	char	*signed_token;
	char	*res;
	char	*tmp;
	char	*tmp2;
	t_cmds	**cmds;
}	t_args;

typedef struct s_vars
{
	int		*in_cmd;
	char	**token;
}	t_vars;

typedef struct s_vars1
{
	int		in_quote;
	int		in_cmd;
}	t_vars1;

int		ft_lexer(char *command);
void	ft_check_incmd(int *in_cmd, t_cmds **cmds);
int		ft_cmp_tok(t_token *tok, t_token *n_tok, int index, char *cmd);
void	ft_join(t_token *n_tok, char *cmd, int index);
int		ftv(char *tok, int i, int in_quote);
int		ft_check(t_token *tok, char *command, int *in_quote, int *i);
int		ft_update(int *index, int *in_quote, t_token *n_token, char *cmd);
void	ft_add_inoutfile(int *in_cmd, t_cmds **cmds, t_token token[]);
void	ft_init(t_token *tok, int *i, int *in_quote, int *in_cmd);
t_cmds	*ft_newcmd(char *cmnd, int flag);
void	ft_cmdadd_back(t_cmds **cmds, t_cmds *new);
t_cmds	*ft_lastcmd(t_cmds **cmds);
t_cmds	*ft_parser(char *cmd, t_seer *seer);
int		ft_update_lexer(int *index, int *in_quote, t_token *n_token, char *cmd);
void	ft_getcmd(int *in_cmd, t_token tok[], t_cmds **cmds, char *c);
void	ft_go_next(t_token token[]);
void	ft_check_pipe(char *cmd, int *in_cmd, int *i);
char	**ft_arr_additem(char **args, char *str, int len);
void	ft_append_herdoc(int *in_cmd, t_cmds **cmds, t_token tok[], char c);
char	*ft_check_sign(t_vars vars, t_seer *seer, t_cmds **cmds);
void	ft_append_cmds(int *in_cmd, t_token tok[], t_cmds **cmds);
void	ft_str_to_env(char **token, t_args *args, int *j);
void	ft_expand_sign(t_vars *vars, t_seer *seer, t_args *args, int *i);
char	*ft_check_env(char *token, t_seer *seer);
char	*ft_join_v3(char *str1, char *str2);
int		ft_checker(char *cmd, int *i, int *in_quote, t_token *tok);
void	ft_update_op(char *str, char **cmd, int *i);
void	ft_cut_string(char *str, char **cmd, int *i, char *op);
void	ft_add_inoutfile(int *in_cmd, t_cmds **cmds, t_token token[]);
void	ft_check_incmd(int *in_cmd, t_cmds **cmds);
int		ft_update_parser(int *idx, int *in_quote, t_token *n_token, char *cmd);
int		ft_update_lexer(int *index, int *in_quote, t_token *n_token, char *cmd);
void	ft_split_wilds(t_cmds **cmds, t_token *tok, int *in_cmd);
void	ft_up_quote(char *cmd, int *i, int *in_quote);
#endif