/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:13:06 by hradoux           #+#    #+#             */
/*   Updated: 2023/01/22 19:04:57 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*					CREATE TREE
 *	créé un AST (arbre synthaxique abstrait) binaire:
 *	c'est une liste chaînée ou chaque node (root dans n'autre cas)
 *	va pouvoir pointer sur 2 nodes (ou roots) et non 1 dans une liste
 *	chainée "classique".
 *	Logique d'éxecution de cette fonction:
 *	- 	lis un str en son entier et retient l'index du dernier && || | rencontré
 *		sachant qu'il y a une precedence entre les symbols : && || < |
 *		donc on veut split d'abord en fonction de && et || puis |
 *	-	dans son "split", les ()) sont prises en compte, mais manque les " et '
 *	Donc pour l'instant, chaque root contient simplement un str correspondant
 *	-	commencant au symbol trouvé si c'est un || && ou |
 *	-	commencant au debut du mot, commande, redirection, fichier si cest pas
 *		une oprande relationnelle (&& || |)
 *	Petit Bonus dans mon AST, les enfants ont un pointer sur l'adresse de
 *	leur pere, permettant ainsi de se déplacer librement dans "l'arbre"
 */

#include "minishell.h"

int	and_or_pipe(t_tree *root, char *input, int index, int prcdnc)
{
	char	*sub1;
	char	*sub2;

	root->input = ft_substr_minishell(input, index, prcdnc % 3);
	sub1 = ft_substr_minishell(input, 0, index);
	sub2 = ft_substr_minishell(input, index + prcdnc % 3, \
	ft_strlen(input) - (index + prcdnc % 3));
	if (!sub1 || !*sub1 || !sub2 || !*sub2)
	{
		ft_putstr_fd("not_bash: parse error near unexpected token `", 2);
		ft_putstr_fd(root->input, 2);
		ft_putstr_fd("'\n", 2);
		if (sub1)
			free(sub1);
		if (sub2)
			free(sub2);
		free (root);
		g_bash.status = 258;
		g_bash.parse_err++;
		return (ERROR);
	}
	root->left = create_tree(sub1, root);
	root->right = create_tree(sub2, root);
	free(input);
	return (SUCCESS);
}

int	bracket(t_tree *root, char *input, int index, int prcdnc)
{
	char	*tmp;

	root->input = ft_substr_brkt_2(input, index);
	if ((prcdnc % 3) == (int) strlen(root->input))
	{
		ft_putstr_fd("not_bash: parse error near unexpected token `", 2);
		ft_putchar_fd(*root->input, 2);
		ft_putstr_fd("'\n", 2);
		free(root->input);
		free(input);
		free (root);
		g_bash.status = 258;
		g_bash.parse_err++;
		return (ERROR);
	}
	tmp = ft_substr_brkt(input, index);
	if (*tmp)
		root->left = create_tree(tmp, root);
	else
		free (tmp);
	free(input);
	return (SUCCESS);
}

int	prcdnc_case(char *input, t_tree *root)
{
	int	index;
	int	prcdnc;

	root->left = NULL;
	root->right = NULL;
	index = precedence(input, &prcdnc);
	if (index == -1)
	{
		free(root);
		return (ERROR);
	}
	if (!prcdnc)
		root->input = input;
	else if (prcdnc > 9)
	{
		if (and_or_pipe(root, input, index, prcdnc))
			return (ERROR);
	}
	else
		if (bracket(root, input, index, prcdnc))
			return (ERROR);
	return (SUCCESS);
}

t_tree	*create_tree(char *input, t_tree *father)
{
	t_tree	*root;

	if (!input || !*input)
		return (NULL);
	root = ft_calloc(sizeof(t_tree), 1);
	if (prcdnc_case(input, root))
		return (NULL);
	root->father = father;
	return (root);
}
