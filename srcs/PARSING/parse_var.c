/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:59:11 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/22 16:59:13 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	var_swap_size(char const *s, char **env)
{
	int		quote;
	size_t	i;

	i = 0;
	quote = 0;
	while (*s)
	{
		if (*s == '$' && quote == 34)
			i += size_dollar_double_quote(&s, env);
		else if (*s == '$' && !quote)
			i += size_dollar_no_quote(&s, env);
		else
			i++;
		if (*s == 39 || *s == 34)
			if (!quote || quote == *s)
				quote = (quote - *s) * -1;
		s++;
	}
	return (i);
}

void	add_back_slash(char *var, char **tmp)
{
	while (var && *var)
	{
		if (*var == 34 || *var == 39)
		{
			*((*tmp)++) = 92;
			*((*tmp)++) = *(var++);
		}
		else
			*((*tmp)++) = *(var++);
	}
}

void	swap_dollar_double_quote_option(char const **s, char **tmp, char **env)
{
	int		i;
	char	*var;

	if (*(*s + 1) == 34 || *(*s + 1) == 39 || *(*s + 1) == 32 || *(*s + 1) == 0)
		*((*tmp)++) = **s;
	else if (*(*s + 1) == '?')
	{
		var = ft_itoa(g_bash.status);
		i = -1;
		while (var[++i])
			*((*tmp)++) = var[i];
		(*s)++;
		free(var);
	}
	else if (*(*s + 1) == 32 || *(*s + 1) == 0)
		*((*tmp)++) = *((*s)++);
	else
	{
		add_back_slash(var_in_env((*s + 1), env), tmp);
		while (!not_alpha_num(*(*s + 1)))
			(*s)++;
	}
}

void	swap_dollar_no_quote_option(char const **s, char **tmp, char **env)
{
	int		i;
	char	*var;

	if (*(*s + 1) == 34 || *(*s + 1) == 39 || *(*s + 1) == 32 || *(*s + 1) == 0)
		*((*tmp)++) = **s;
	else if (*(*s + 1) == '?')
	{
		var = ft_itoa(g_bash.status);
		i = -1;
		while (var[++i])
			*((*tmp)++) = var[i];
		(*s)++;
		free(var);
	}
	else
	{
		add_back_slash(var_in_env(*s + 1, env), tmp);
		while (!not_alpha_num(*(*s + 1)))
			(*s)++;
	}
}

char	*swap_var(char const *s, char **env)
{
	int		quote;
	char	*tmp;
	char	*tmp_start;

	quote = 0;
	tmp = ft_calloc(var_swap_size(s, env) + 1, sizeof(char));
	tmp_start = tmp;
	while (*s)
	{
		if (*s == 92 && (*(s + 1) == 34 || *(s + 1) == 39))
			s++;
		if (*s == '$' && quote == 34)
			swap_dollar_double_quote_option(&s, &tmp, env);
		else if (*s == '$' && !quote)
			swap_dollar_no_quote_option(&s, &tmp, env);
		else
			*(tmp++) = *s;
		if (*s == 39 || *s == 34)
			if (!quote || quote == *s)
				quote = (quote - *s) * -1;
		s++;
	}
	return (tmp_start);
}
