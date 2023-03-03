/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:51 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 13:25:51 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_exists(char **env, char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	while (env[j])
	{
		if (ft_strncmp(env[j], arg, i) == 0)
			return (j);
		j++;
	}
	return (ERROR);
}

char	**ft_add_env_arg(char **env, char *arg, int incr[3], char **tab)
{
	if (arg_exists(env, arg) != ERROR)
	{
		free(tab[arg_exists(env, arg)]);
		tab[arg_exists(env, arg)] = ft_calloc(sizeof(char), (incr[0] + 1));
		while (incr[2] < incr[0])
		{
			tab[arg_exists(env, arg)][incr[2]] = arg[incr[2]];
			incr[2]++;
		}
		return (tab);
	}
	tab[incr[1]] = ft_calloc(sizeof(char), (incr[0] + 1));
	while (incr[2] < incr[0])
	{
		tab[incr[1]][incr[2]] = arg[incr[2]];
		incr[2]++;
	}
	return (tab);
}

char	**ft_add_env(char **env, char *arg)
{
	int		incr[3];
	char	**tab;

	incr[0] = 0;
	incr[1] = 0;
	incr[2] = 0;
	while (arg[incr[0]] != '\0')
		incr[0]++;
	while (env[incr[1]])
		incr[1]++;
	if (arg_exists(env, arg) == ERROR)
		tab = ft_calloc(sizeof(char *), (incr[1] + 2));
	else
		tab = ft_calloc(sizeof(char *), (incr[1] + 1));
	incr[1] = 0;
	while (env[incr[1]])
	{
		tab[incr[1]] = ft_strdup(env[incr[1]]);
		incr[1]++;
	}
	return (ft_add_env_arg(env, arg, incr, tab));
}
