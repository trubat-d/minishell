/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:29:23 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 07:29:23 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_putstr_fd("pwd: error retrieving current directory: ", 2);
		perror("getcwd: cannot access parent directories: ");
		return (1);
	}
	ft_putstr_fd(pwd, 1);
	ft_putchar_fd('\n', 1);
	free(pwd);
	return (SUCCESS);
}
