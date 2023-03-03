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

void	ft_print_tab(char **tab)
{
	int		i;
	int		j;
	char	*str;
	int		has_equal;

	j = 0;
	while (tab[j])
	{
		has_equal = 0;
		str = tab[j++];
		i = 0;
		ft_putstr_fd("declare -x ", 1);
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			if (str[i++] == '=')
			{
				has_equal = 1;
				ft_putstr_fd("\"", 1);
			}
		}
		if (has_equal)
			ft_putstr_fd("\"", 1);
		ft_putstr_fd("\n", 1);
	}
}

char	**sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				tmp = ft_strdup(tab[i]);
				free(tab[i]);
				tab[i] = ft_strdup(tab[j]);
				free(tab[j]);
				tab[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_export_error(char *args)
{
	int	i;

	i = 0;
	if (args[i] == '=')
	{
		ft_putstr_fd("not_bash: export: `", 2);
		ft_putstr_fd(args, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	while (args[i] && args[i] != '=')
	{
		if ((!i && (ft_isdigit(args[i]) || args[i] == '=')) \
		|| not_alpha_num(args[i]))
		{
			ft_putstr_fd("not_bash: export: `", 2);
			ft_putstr_fd(args, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_export_loop(char **args, t_bash *bash, char **tab, int *status)
{
	int	j;

	j = 1;
	while (args[j])
	{
		if (!ft_export_error(args[j]))
		{
			tab = ft_add_env(bash->env, args[j]);
			if (bash->env)
				free_tab(bash->env);
			bash->env = tab;
		}
		else
			*status = 1;
		j++;
	}
}

int	ft_export(t_bash *bash, char **args)
{
	int		j;
	char	**tab;
	int		status;

	status = 0;
	j = 1;
	if (args[j] != NULL)
	{
		tab = 0;
		ft_export_loop(args, bash, tab, &status);
	}
	else
	{
		tab = ft_tabdup(bash->env);
		ft_print_tab(sort_tab(tab));
		free_tab(tab);
	}
	return (status);
}
