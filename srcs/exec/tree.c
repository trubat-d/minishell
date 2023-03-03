/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:28:36 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:28:54 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_tree_two(t_tree *tree, t_bash *bash)
{
	if (tree->token == OR)
	{
		if (exec_tree(tree->left, bash) != SUCCESS)
		{
			bash->tmp_fd = dup(STDIN_FILENO);
			return (exec_tree(tree->right, bash));
		}
	}
	else if (tree->token == PIPE)
		return (pipe_exec(tree, bash));
	else if (tree->token == APPEND)
		return (redir_double_right(tree, bash));
	else if (tree->token == HR_DC)
		return (redir_double_left(tree, bash));
	else if (tree->token == OUT_FILE)
		return (redir_right(tree, bash));
	else if (tree->token == IN_FILE)
		return (redir_left(tree, bash));
	return (SUCCESS);
}

int	exec_tree(t_tree *tree, t_bash *bash)
{
	if (tree == NULL)
		return (SUCCESS);
	classify(tree, bash);
	if (tree->token == CMD || tree->token == BUILT_IN)
		return (start_exec(tree, bash));
	else if (tree->token == NOPE)
	{
		ft_putstr_fd("not_bash: ", 2);
		ft_putstr_fd(((t_error *)tree->type)->cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		g_bash.status = 127;
		return (ERROR);
	}
	else if (tree->token == AND)
	{
		if (exec_tree(tree->left, bash) == SUCCESS)
		{
			bash->tmp_fd = dup(STDIN_FILENO);
			return (exec_tree(tree->right, bash));
		}
	}
	return (exec_tree_two(tree, bash));
}
