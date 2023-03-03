/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precedence_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/20 18:33:35 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_case_1(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (IN_FILE);
	else if (c == '>')
		return (OUT_FILE);
	else if (c == '&')
	{
		ft_putstr_fd("not_bash: syntax error near unexpected token `", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		return (ERROR);
	}
	return (0);
}

int	define_case_2(const char *line, char c)
{
	int	count;

	count = 0;
	while (*(line + count) == c)
		count++;
	if (count > 2)
	{
		ft_putstr_fd("not_bash: syntax error near unexpected token `", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		return (ERROR);
	}
	else if (count == 2)
	{
		if (c == '|' || c == '&')
			return (ANDOR);
		else if (c == '<')
			return (HR_DC);
		else if (c == '>')
			return (APPEND);
	}
	else
		return (define_case_1(c));
	return (0);
}
