/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:34:12 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/17 13:34:19 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_exec_pipe(t_tree *tree, t_bash *bash, t_tree *tmp)
{
	if (bash->hrdc)
		bash->tmp_fd = bash->fd[0];
	if (pipe(bash->fd) == -1)
		return (ERROR);
	if ((tmp->father->father == NULL || tmp->father->father->token != PIPE) \
	&& tmp->father->right == tmp)
	{
		if (tree->token == CMD)
			lst_cmd((t_cmd *) tree->type, bash);
		else
			lst_built_in((t_builtin *) tree->type, bash);
	}
	else
	{
		if (tree->token == CMD)
			all_cmd((t_cmd *)tree->type, bash);
		else
			all_built_in((t_builtin *) tree->type, bash);
	}
	return (SUCCESS);
}

int	start_exec(t_tree *tree, t_bash *bash)
{
	t_tree	*tmp;

	tmp = tree;
	while (tmp->father != NULL && tmp->father->token >= \
	OUT_FILE && tmp->father->token <= HR_DC)
		tmp = tmp->father;
	if (tmp->father == NULL || tmp->father->token != PIPE)
	{
		if (tree->token == CMD)
			return (cmd((t_cmd *)tree->type, bash));
		else
			return (g_bash.status = built_in((t_builtin *) tree->type, bash));
	}
	else if (tmp->father->token == PIPE)
		return (start_exec_pipe(tree, bash, tmp));
	return (SUCCESS);
}
