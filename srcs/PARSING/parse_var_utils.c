/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:14 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/27 13:59:17 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_alpha_num(char c)
{
	if (ft_isalnum(c) || c == 95)
		return (0);
	return (1);
}

//$1-9 can be replaced
char	*var_in_env(char const *s, char **env)
{
	int	i;

	while (*env)
	{
		i = 0;
		while (s[i] && (*env)[i] == s[i] && (*env)[i] != '=')
			i++;
		if ((*env)[i] == '=' && not_alpha_num(s[i]))
			return (&(*env)[i + 1]);
		env++;
	}
	return (NULL);
}

size_t	var_length(char const *s, char **env)
{
	int		i;
	char	*tmp;
	size_t	quote;

	tmp = var_in_env(s, env);
	if (!tmp)
		return (0);
	quote = 0;
	i = -1;
	while (*(tmp + (++i)))
		if (*(tmp + i) == 34 || *(tmp + i) == 39)
			quote++;
	return (ft_strlen(tmp) + quote);
}

size_t	size_dollar_double_quote(char const **s, char **env)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (*(*s + 1) == 34 || *(*s + 1) == 39 || *(*s + 1) == 32 || *(*s + 1) == 0)
		i++;
	else if (*(*s + 1) == '?')
	{
		tmp = ft_itoa(g_bash.status);
		i += ft_strlen(tmp);
		free(tmp);
		(*s)++;
	}
	else
	{
		i += var_length((*s) + 1, env);
		while (!not_alpha_num(*(*s + 1)))
			(*s)++;
	}
	return (i);
}

size_t	size_dollar_no_quote(char const **s, char **env)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (*(*s + 1) == 34 || *(*s + 1) == 39 || *(*s + 1) == 32 || *(*s + 1) == 0)
		i++;
	else if (*(*s + 1) == '?')
	{
		tmp = ft_itoa(g_bash.status);
		i += ft_strlen(tmp);
		free(tmp);
		(*s)++;
	}
	else
	{
		i += (var_length((*s + 1), env));
		while (!not_alpha_num(*(*s + 1)))
			(*s)++;
	}
	return (i);
}
