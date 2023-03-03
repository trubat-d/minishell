/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:10:36 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/09 11:10:36 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_left(t_tree *tree, t_bash *bash)
{
	bash->in_fd = open(tree->input + 1, O_RDONLY);
	if (bash->in_fd == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(tree->input + 1, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_bash.status = 1;
		return (ERROR);
	}
	bash->hrdc = 0;
	return (exec_tree(tree->left, bash));
}

int	redir_right(t_tree *tree, t_bash *bash)
{
	bash->out_fd = open(tree->input + 1, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (bash->out_fd == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(tree->input + 1, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_bash.status = 1;
		return (ERROR);
	}
	return (exec_tree(tree->left, bash));
}

int	redir_double_right(t_tree *tree, t_bash *bash)
{
	bash->out_fd = open(tree->input + 2, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (bash->out_fd == -1)
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(tree->input + 2, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_bash.status = 1;
		return (ERROR);
	}
	return (exec_tree(tree->left, bash));
}

void	redir_double_left_loop(t_tree *tree, t_bash *bash, char *line)
{
	while (1)
	{
		set_signal(2);
		line = readline("not_heredoc> ");
		if (!line)
		{
			free(line);
			close(*(bash->fd + 1));
			exit(SUCCESS);
		}
		if (ft_strcmp(line, tree->input + 2) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, *(bash->fd + 1));
		ft_putstr_fd("\n", *(bash->fd + 1));
		free(line);
	}
	close(*(bash->fd + 1));
	exit(SUCCESS);
}

int	redir_double_left(t_tree *tree, t_bash *bash)
{
	int		status;
	char	*line;

	if (pipe(bash->fd) == -1)
		return (ERROR);
	bash->pid = fork();
	if (bash->pid == -1)
		ft_putstr_fd("not_bash: Fork failed\n", 2);
	else if (!bash->pid)
	{
		line = 0;
		redir_double_left_loop(tree, bash, line);
	}
	waitpid(bash->pid, &status, 0);
	close(*(bash->fd + 1));
	bash->hrdc = 1;
	return (sig_redir_handler(tree, bash, status));
}
