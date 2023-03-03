/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:33:50 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:33:56 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_cmd_no_pid(t_cmd *cmd, t_bash *bash, char *path_cmd)
{
	tty_attribute(0);
	if (bash->in_fd > 2)
		dup2(bash->in_fd, STDIN_FILENO);
	else
		dup2(bash->tmp_fd, STDIN_FILENO);
	if (bash->out_fd > 2)
		dup2(bash->out_fd, STDOUT_FILENO);
	else
		dup2(*(bash->fd + 1), STDOUT_FILENO);
	if (bash->in_fd > 2)
		close(bash->in_fd);
	if (bash->out_fd > 2)
		close(bash->out_fd);
	close(bash->tmp_fd);
	close(*bash->fd);
	close(*(bash->fd + 1));
	if (execve(path_cmd, cmd->args, bash->env) == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		perror(path_cmd);
		exit(errno);
	}
}
