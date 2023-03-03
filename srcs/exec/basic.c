/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:09:28 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/09 11:09:28 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(t_builtin *builtin, t_bash *bash)
{
	if (ft_strcmp(builtin->cmd, "cd") == 0)
		return (ft_cd(builtin->args, bash));
	if (ft_strcmp(builtin->cmd, "echo") == 0)
		return (ft_echo(builtin->args, bash));
	if (ft_strcmp(builtin->cmd, "env") == 0)
		return (ft_env(bash));
	if (ft_strcmp(builtin->cmd, "exit") == 0)
		return (ft_exit(builtin->args));
	if (ft_strcmp(builtin->cmd, "exit") == 0)
		return (ft_exit(builtin->args));
	if (ft_strcmp(builtin->cmd, "export") == 0)
		return (ft_export(bash, builtin->args));
	if (ft_strcmp(builtin->cmd, "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(builtin->cmd, "unset") == 0)
		return (ft_unset(builtin->args, bash, 0));
	return (SUCCESS);
}

int	cmd_dir_err_acc(t_cmd *cmd, struct stat statbuf, char *path_cmd)
{
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(cmd->cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		g_bash.status = 126;
		return (ERROR);
	}
	if (access(path_cmd, R_OK | X_OK | F_OK))
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(cmd->cmd);
		g_bash.status = 126;
		return (ERROR);
	}
	return (SUCCESS);
}

void	cmd_child(t_bash *bash, char *path_cmd, t_cmd *cmd)
{
	tty_attribute(0);
	if (bash->hrdc)
	{
		dup2(*bash->fd, STDIN_FILENO);
		close(*bash->fd);
	}
	else
		dup2(bash->in_fd, STDIN_FILENO);
	dup2(bash->out_fd, STDOUT_FILENO);
	if (bash->in_fd > 2)
		close(bash->in_fd);
	if (bash->out_fd > 2)
		close(bash->out_fd);
	if (execve(path_cmd, cmd->args, bash->env) == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(path_cmd);
		exit(errno);
	}
}

int	cmd(t_cmd *cmd, t_bash *bash)
{
	int			status;
	char		*path_cmd;
	struct stat	statbuf;

	path_cmd = get_path_cmd(cmd->cmd, bash->env);
	stat(path_cmd, &statbuf);
	if (cmd_dir_err_acc(cmd, statbuf, path_cmd))
		return (ERROR);
	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
		cmd_child(bash, path_cmd, cmd);
	catch_status(bash, &status);
	free(path_cmd);
	return (interpret_status(status));
}
