/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:09:46 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/09 11:09:46 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct s_cmd
{
	char		*cmd;
	char		**args;
}		t_cmd;

typedef struct s_builtin
{
	char		*cmd;
	char		**args;
}		t_builtin;

typedef struct s_error
{
	char		*cmd;
	char		**args;
}		t_error;

int		pipe_exec(t_tree *tree, t_bash *bash);
int		start_exec(t_tree *tree, t_bash *bash);

int		built_in(t_builtin *builtin, t_bash *bash);
int		cmd(t_cmd *cmd, t_bash *bash);

void	lst_built_in(t_builtin *builtin, t_bash *bash);
void	all_built_in(t_builtin *builtin, t_bash *bash);

void	lst_cmd(t_cmd *cmd, t_bash *bash);
void	all_cmd(t_cmd *cmd, t_bash *bash);

int		redir_right(t_tree *tree, t_bash *bash);
int		redir_double_right(t_tree *tree, t_bash *bash);

int		redir_double_left(t_tree *tree, t_bash *bash);
int		redir_left(t_tree *tree, t_bash *bash);
int		interpret_status(int status);
int		sig_redir_handler(t_tree *tree, t_bash *bash, int status);
void	all_cmd_no_pid(t_cmd *cmd, t_bash *bash, char *path_cmd);

void	catch_status(t_bash *bash, int *status);

#endif