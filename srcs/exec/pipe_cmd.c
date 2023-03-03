/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:33:50 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:33:56 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_cmd_access(t_cmd *cmd, struct stat statbuf, char *path_cmd)
{
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(cmd->cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
	if (access(path_cmd, R_OK | X_OK | F_OK))
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(cmd->cmd);
		exit(126);
	}
}

void	all_cmd(t_cmd *cmd, t_bash *bash)
{
	char		*path_cmd;
	struct stat	statbuf;

	path_cmd = get_path_cmd(cmd->cmd, bash->env);
	stat(path_cmd, &statbuf);
	all_cmd_access(cmd, statbuf, path_cmd);
	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
		all_cmd_no_pid(cmd, bash, path_cmd);
	close(bash->fd[1]);
	close(bash->tmp_fd);
	bash->tmp_fd = bash->fd[0];
	free(path_cmd);
}

void	lst_cmd_no_pid(t_cmd *cmd, t_bash *bash, char *path_cmd)
{
	tty_attribute(0);
	if (bash->in_fd > 2)
		dup2(bash->in_fd, STDIN_FILENO);
	else
		dup2(bash->tmp_fd, STDIN_FILENO);
	if (bash->out_fd > 2)
		dup2(bash->out_fd, STDOUT_FILENO);
	if (bash->in_fd > 2)
		close(bash->in_fd);
	if (bash->out_fd > 2)
		close(bash->out_fd);
	close(bash->tmp_fd);
	if (execve(path_cmd, cmd->args, bash->env) == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(path_cmd);
		exit(errno);
	}
}

void	lst_cmd_access(t_cmd *cmd, struct stat statbuf, char *path_cmd)
{
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(cmd->cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
	if (access(path_cmd, R_OK | X_OK | F_OK))
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(cmd->cmd);
		exit (126);
	}
}

void	lst_cmd(t_cmd *cmd, t_bash *bash)
{
	char		*path_cmd;
	struct stat	statbuf;

	path_cmd = get_path_cmd(cmd->cmd, bash->env);
	stat(path_cmd, &statbuf);
	lst_cmd_access(cmd, statbuf, path_cmd);
	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
		lst_cmd_no_pid(cmd, bash, path_cmd);
	close(bash->tmp_fd);
	free(path_cmd);
}
