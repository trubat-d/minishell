/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:30:33 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/14 15:16:13 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

enum
{
	BUILT_IN = 1,
	CMD = 2,
	NOPE = 3,
	OUT_FILE = 4,
	APPEND = 5,
	IN_FILE = 7,
	HR_DC = 8,
	PIPE = 10,
	OR = 12,
	AND = 13,
	ANDOR = 14,
};

typedef struct s_bash
{
	int		parse_err;
	int		fd[2];
	int		in_fd;
	int		out_fd;
	int		tmp_fd;
	int		hrdc;
	char	*input;
	char	**env;
	pid_t	pid;
}	t_bash;

typedef struct s_tree
{
	char			*input;
	void			*type;
	int				token;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*father;
}		t_tree;

int		define_precedence(char *line);
int		precedence(char *line, int *prcdnc);
t_tree	*create_tree(char *input, t_tree *father);
int		define_case_1(char c);
int		define_case_2(const char *line, char c);

#endif