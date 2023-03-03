/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precedence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:02:53 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/14 15:17:15 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*			DEFINE_PRECEDENCE
 * 	Permet de savoir si le caractere donné est un && || ou |
 */

int	define_precedence(char *line)
{
	if (*line == '<' || *line == '>' || *line == '&' || *line == '|')
		return (define_case_2(line, *line));
	return (0);
}

void	quote_prnths_check(const char *line, int i, int *quote, int *prnths)
{
	if ((*(line + i) == 39 || *(line + i) == 34)
		&& (!*quote || *quote == *(line + i)))
		*quote = (*quote - *(line + i)) * (-1);
	if ((*(line + i) == '(' || *(line + i) == ')') && !*quote)
		*prnths += (41 - *(line + i)) * 2 - 1;
}

void	precedence_index(int *prcdnc, int tmp, int *index, int *i)
{
	if (*prcdnc <= tmp && (!(*prcdnc) || tmp > 9 || tmp - *prcdnc > 1))
	{
		*prcdnc = tmp;
		*index = *i;
	}
	*i += tmp % 3 - 1;
}

/*			PRECEDENCE
 * 	Permet de trouver l'index du dernier operateur relationnel
 * 	a la precedence la plus haute.
 */
int	precedence(char *line, int *prcdnc)
{
	int	i;
	int	tmp;
	int	quote;
	int	index;
	int	prnths;

	i = -1;
	index = 0;
	*prcdnc = 0;
	prnths = 0;
	quote = 0;
	while (*(line + (++i)))
	{
		quote_prnths_check(line, i, &quote, &prnths);
		if (!prnths && !quote)
		{
			tmp = define_precedence(line + i);
			if (tmp == ERROR)
				return (ERROR);
			else if (tmp)
				precedence_index(prcdnc, tmp, &index, &i);
		}
	}
	return (index);
}

/*int	precedence(char *line, int *prcdnc)
{
	int	i;
	int	tmp;
	int	quote;
	int	index;
	int	prnths;

	i = -1;
	index = 0;
	*prcdnc = 0;
	prnths = 0;
	quote = 0;
	while (*(line + (++i)))
	{
		quote_prnths_check(line, i, &quote, &prnths);
		tmp = define_precedence(line + i);
		if (tmp == -1)
			return (ERROR);
		if (!prnths && !quote && tmp)
			precedence_index(prcdnc, tmp, &index, i);
		if (tmp)
			i += tmp % 3 - 1;
	}
	return (index);
}*/