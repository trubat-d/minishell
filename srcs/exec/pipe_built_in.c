/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:53:08 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:53:11 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_built_in(t_builtin *builtin, t_bash *bash)
{
	int	status;

	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
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
		status = built_in(builtin, bash);
		exit(status);
	}
	close(bash->tmp_fd);
}

void	all_built_in_std(t_bash *bash)
{
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
}

void	all_built_in(t_builtin *builtin, t_bash *bash)
{
	int	status;

	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
	{
		tty_attribute(0);
		all_built_in_std(bash);
		close(bash->tmp_fd);
		close(*bash->fd);
		close(*(bash->fd + 1));
		status = built_in(builtin, bash);
		exit(status);
	}
	close(bash->fd[1]);
	close(bash->tmp_fd);
	bash->tmp_fd = bash->fd[0];
}
