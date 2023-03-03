/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:10:36 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/09 11:10:36 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sig_redir_handler(t_tree *tree, t_bash *bash, int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
		{
			printf("\n");
			g_bash.status = 1;
			return (ERROR);
		}
	}
	else if (WIFEXITED(status))
	{
		if (status)
			return (ERROR);
		return (exec_tree(tree->left, bash));
	}
	return (exec_tree(tree->left, bash));
}
