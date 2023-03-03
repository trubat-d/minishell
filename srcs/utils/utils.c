/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:23:36 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/17 15:23:36 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	full_white_space(char *line)
{
	while (*line)
	{
		if (!white_space(*line))
			return (1);
		line++;
	}
	return (0);
}

char	*get_env(char *name, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == name[j])
			j++;
		if (env[i][j] == '=')
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}

char	**ft_tabdup(char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	new_tab = (char **) ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new_tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
