/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:27:52 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 13:27:52 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env_var(char **env, int index)
{
	int	i;

	i = index;
	free(env[i]);
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
}

int	ft_unset_error(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((!i && ft_isdigit(args[i])) || not_alpha_num(args[i]))
		{
			ft_putstr_fd("not_bash: unset: `", 2);
			ft_putstr_fd(args, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **args, t_bash *bash, int status)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	status = 0;
	while (args[++i])
	{
		j = -1;
		if (!ft_unset_error(args[i]))
		{
			while ((bash->env)[++j])
			{
				k = 0;
				while (bash->env[j][k] != '=' && bash->env[j][k] != '\0')
					k++;
				if (ft_strlen(args[i]) == (size_t)k && \
				!ft_strncmp(args[i], bash->env[j], k))
					remove_env_var(bash->env, j);
			}
		}
		else
			status = 1;
	}
	return (status);
}
