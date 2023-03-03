/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:33:00 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:33:39 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_last_pipe(t_tree *tree)
{
	t_tree	*tmp;

	tmp = tree;
	while (tmp->father != NULL && tmp->father->token >= 4 \
	&& tmp->father->token <= 8)
		tmp = tmp->father;
	if (tree->father == NULL || tree->father->token != PIPE)
		return (1);
	return (0);
}

void	catch_status(t_bash *bash, int *status)
{
	int		wait;

	while (1)
	{
		wait = waitpid(-1, status, 0);
		if (wait == bash->pid)
		{
			if (WIFSIGNALED(*status))
				g_bash.status = 128 + WTERMSIG(*status);
			else if (WIFEXITED(*status))
				g_bash.status = WEXITSTATUS(*status);
		}
		else if (wait == -1)
			break ;
	}
}

int	interpret_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
		{
			printf("Quit : %d\n", status);
			return (ERROR);
		}
		else if (WTERMSIG(status) == 2)
		{
			printf("\n");
			return (ERROR);
		}
	}
	else if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
			return (ERROR);
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	pipe_exec(t_tree *tree, t_bash *bash)
{
	int		status;

	status = 0;
	bash->hrdc = 0;
	bash->in_fd = 0;
	bash->out_fd = 1;
	exec_tree(tree->left, bash);
	bash->hrdc = 0;
	bash->in_fd = 0;
	bash->out_fd = 1;
	exec_tree(tree->right, bash);
	if (check_last_pipe(tree))
		catch_status(bash, &status);
	return (interpret_status(status));
}
