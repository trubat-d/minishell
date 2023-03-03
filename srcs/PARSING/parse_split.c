/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:42:27 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/22 18:42:29 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_count_parse(char const *s, char c)
{
	int	i;
	int	quote;
	int	word_count;

	i = 0;
	quote = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while ((s[i] && s[i] != c) || (s[i] && quote))
		{
			if ((s[i] == 39 || s[i] == 34) && (!i || s[i - 1] != 92))
				if (!quote || quote == s[i])
					quote = (quote - s[i]) * -1;
			i++;
		}
	}
	return (word_count);
}

int	string_size_parse(char const *s, char c)
{
	int	i;
	int	tot;
	int	quote;

	i = 0;
	tot = 0;
	quote = 0;
	while ((s[i] && s[i] != c) || (s[i] && quote))
	{
		if (s[i] == 92 && (s[i + 1] == 34 || s[i + 1] == 39))
			i++;
		if ((s[i] == 39 || s[i] == 34) && (!i || s[i - 1] != 92))
		{
			if (!quote || quote == s[i])
				quote = (quote - s[i]) * -1;
			if (s[i] != quote && quote)
				tot++;
		}
		else
			tot++;
		i++;
	}
	return (tot);
}

void	get_string_parse(char **tmp, char const *s, char c)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while ((s[i] && s[i] != c) || (s[i] && quote))
	{
		if (s[i] == 92 && (s[i + 1] == 34 || s[i + 1] == 39))
			i++;
		if ((s[i] == 39 || s[i] == 34) && (!i || s[i - 1] != 92))
		{
			if (!quote || quote == s[i])
				quote = (quote - s[i]) * -1;
			if (s[i] != quote && quote)
				*((*tmp)++) = s[i];
		}
		else
			*((*tmp)++) = s[i];
		i++;
	}
}

char	*dup_string_parse(char const *s, char c)
{
	char	*tmp;
	char	*tmp_start;

	tmp = ft_calloc(string_size_parse(s, c) + 1, sizeof(char));
	tmp_start = tmp;
	get_string_parse(&tmp, s, c);
	return (tmp_start);
}

char	**split_parse(char const *s, char c)
{
	int		i;
	int		quote;
	char	**tmp;

	tmp = ft_calloc(word_count_parse(s, c) + 1, sizeof(char *));
	i = 0;
	quote = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			*tmp++ = dup_string_parse(&s[i], c);
		while ((s[i] && s[i] != c) || (s[i] && quote))
		{
			if ((s[i] == 39 || s[i] == 34) && (!i || s[i - 1] != 92))
				if (!quote || quote == s[i])
					quote = (quote - s[i]) * -1;
			i++;
		}
	}
	return (tmp - word_count_parse(s, c));
}
