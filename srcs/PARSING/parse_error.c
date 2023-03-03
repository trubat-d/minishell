/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:14 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/27 13:59:17 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char c)
{
	ft_putstr_fd("not_bash: syntax error near unexpected token ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\n", 2);
	g_bash.status = 258;
	return (ERROR);
}

int	define_error(int *prnths, int *quote, char *line)
{
	int		i;
	int		tmp;

	i = -1;
	while (*(line + (++i)))
	{
		if ((*(line + i) == 39 || *(line + i) == 34)
			&& (!*quote || *quote == *(line + i)))
			*quote = (*quote - *(line + i)) * -1;
		if ((*(line + i) == '(' || *(line + i) == ')') && !*quote)
			*prnths += (41 - *(line + i)) * 2 - 1;
		tmp = define_precedence(line + i);
		if (tmp == -1)
			return (1);
		else if (tmp)
			i += tmp % 3 - 1;
	}
	return (0);
}

int	parse_error(char *line)
{
	int	quote;
	int	prnths;

	if (!line)
		return (SUCCESS);
	quote = 0;
	prnths = 0;
	if (define_error(&prnths, &quote, line))
		return (ERROR);
	if (prnths)
		return (error_message((char) prnths));
	if (quote)
		return (error_message((char) quote));
	return (SUCCESS);
}
