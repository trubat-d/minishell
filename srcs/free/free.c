/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:39:59 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/09 10:12:26 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		tab[i] = NULL;
		i--;
	}
	free(tab);
}

void	free_tree(t_tree *tree)
{
	if (tree->left)
		free_tree(tree->left);
	if (tree->right)
		free_tree(tree->right);
	if (tree->token == BUILT_IN)
	{
		free_tab(((t_builtin *)tree->type)->args);
		free(tree->type);
	}
	if (tree->token == CMD)
	{
		free_tab(((t_cmd *)tree->type)->args);
		free(tree->type);
	}
	if (tree->token == NOPE)
	{
		free_tab(((t_error *) tree->type)->args);
		free(tree->type);
	}
	free(tree->input);
	free(tree);
}
