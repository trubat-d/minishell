/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:10:04 by hradoux           #+#    #+#             */
/*   Updated: 2023/03/01 19:10:06 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tolower_str(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = (char) ft_tolower((*str)[i]);
		i++;
	}
}

int	is_builtin(char *cmd)
{
	ft_tolower_str(&cmd);
	if (ft_strcmp(cmd, "cd") == 0)
		return (2);
	if (ft_strcmp(cmd, "echo") == 0)
		return (4);
	if (ft_strcmp(cmd, "env") == 0)
		return (3);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (6);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (3);
	if (ft_strcmp(cmd, "unset") == 0)
		return (5);
	return (0);
}
