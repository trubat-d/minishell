/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:21:17 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 07:21:17 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <errno.h>
# include <sys/stat.h>

# include "../libft/include/libft.h"
# include "ast.h"
# include "exec.h"
# include "buildins.h"
# include "free.h"
# include "parsing.h"
# include "utils.h"

typedef struct s_global
{
	int	status;
	int	parse_err;
}	t_global;

t_global	g_bash;

int		exec_tree(t_tree *tree, t_bash *bash);

#endif