/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:27:18 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 13:27:18 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_validity(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	set_env(char *name, char *value, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			tmp = ft_strjoin(name, "=");
			env[i] = ft_strjoin(tmp, value);
			free(tmp);
			return ;
		}
		i++;
	}
}

int	ft_env(t_bash *bash)
{
	int	i;

	i = 0;
	while ((bash->env)[i])
	{
		if (!check_validity((bash->env)[i]))
		{
			i++;
			continue ;
		}
		ft_putstr_fd((bash->env)[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	return (SUCCESS);
}
