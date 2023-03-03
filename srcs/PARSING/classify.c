/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/20 18:33:35 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	classify_builtin(char **word, t_tree *tree)
{
	t_builtin	*type_built;

	type_built = ft_calloc(sizeof(t_builtin), 1);
	type_built->cmd = word[0];
	type_built->args = word;
	tree->type = type_built;
	tree->token = BUILT_IN;
	return (1);
}

int	classify_cmd(char **word, t_tree *tree)
{
	t_cmd		*type_cmd;

	type_cmd = ft_calloc(sizeof(t_cmd), 1);
	type_cmd->cmd = word[0];
	type_cmd->args = word;
	tree->type = type_cmd;
	tree->token = CMD;
	return (1);
}

int	classify_nope(char **word, t_tree *tree)
{
	t_error	*type_error;

	tree->token = NOPE;
	type_error = ft_calloc(sizeof(t_error), 1);
	type_error->cmd = word[0];
	type_error->args = word;
	tree->type = type_error;
	return (1);
}

int	classify_token(char **word, t_tree *tree)
{
	if (ft_strncmp(word[0], "&&", 2) == 0)
		tree->token = AND;
	else if (ft_strncmp(word[0], "||", 2) == 0)
		tree->token = OR;
	else if (ft_strncmp(word[0], "|", 1) == 0)
		tree->token = PIPE;
	else if (ft_strncmp(word[0], "<<", 2) == 0)
		tree->token = HR_DC;
	else if (ft_strncmp(word[0], ">>", 2) == 0)
		tree->token = APPEND;
	else if (ft_strncmp(word[0], ">", 1) == 0)
		tree->token = OUT_FILE;
	else if (ft_strncmp(word[0], "<", 1) == 0)
		tree->token = IN_FILE;
	else
		return (0);
	return (1);
}

int	classify(t_tree *tree, t_bash *bash)
{
	char		*tmp;
	char		*path;
	char		**word;

	tmp = swap_var(tree->input, bash->env);
	word = split_parse(tmp, 32);
	free(tmp);
	path = get_path_cmd(word[0], bash->env);
	if (is_builtin(word[0]))
		classify_builtin(word, tree);
	else if (path)
		classify_cmd(word, tree);
	else if (!classify_token(word, tree))
		classify_nope(word, tree);
	if (tree->token >= 4 && tree->token <= 14)
		free_tab(word);
	free(path);
	return (SUCCESS);
}
