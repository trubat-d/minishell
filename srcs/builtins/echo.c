/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:29:01 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 07:29:01 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_argument(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i] != '-')
			return (0);
		i++;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
	}
	return (i);
}

void	ft_echo_loop(int *n_flag, char **args, int fd)
{
	int	i;
	int	var_check;

	i = 1;
	var_check = 1;
	while (args[i])
	{
		if (var_check && check_argument(args[i]))
		{
			*n_flag = 1;
			i++;
			continue ;
		}
		else
			var_check = 0;
		ft_putstr_fd(args[i], fd);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", fd);
		i++;
	}
}

int	ft_echo(char **args, t_bash *bash)
{
	int	n_flag;

	n_flag = 0;
	if (args[1] == NULL)
		ft_putstr_fd("\n", bash->out_fd);
	else
	{
		ft_echo_loop(&n_flag, args, bash->out_fd);
		if (n_flag == 0)
			ft_putstr_fd("\n", bash->out_fd);
	}
	return (0);
}
