/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:29:33 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 07:29:33 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_home_error(char **argv, t_bash *bash, char **path)
{
	if (argv[1] == NULL)
	{
		*path = get_env("HOME", bash->env);
		if (!(*path))
		{
			ft_putstr_fd("not_bash: cd: HOME not set\n", 2);
			return (1);
		}
	}
	else if (ft_strncmp(argv[1], "-", 2) == 0)
		*path = get_env("OLDPWD", bash->env);
	else
		*path = argv[1];
	return (0);
}

int	ft_path_error(char **argv, const char *path)
{
	if (path == NULL)
	{
		ft_putstr_fd("not_bash: cd: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	ft_chdir_error(char **argv, char *path, char *oldpwd)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("not_bash: cd: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free(oldpwd);
		return (1);
	}
	return (0);
}

int	ft_pwd_error(const char *pwd)
{
	if (pwd == NULL)
	{
		ft_putstr_fd("cd: error retrieving current directory: ", 2);
		perror("getcwd: cannot access parent directories: ");
		return (1);
	}
	return (0);
}

int	ft_cd(char **argv, t_bash *bash)
{
	char	*path;
	char	*oldpwd;
	char	*pwd;

	path = 0;
	if (ft_home_error(argv, bash, &path))
		return (1);
	if (ft_path_error(argv, path))
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (ft_chdir_error(argv, path, oldpwd))
		return (1);
	pwd = getcwd(NULL, 0);
	if (ft_pwd_error(pwd))
		return (1);
	set_env("OLDPWD", oldpwd, bash->env);
	set_env("PWD", pwd, bash->env);
	free(pwd);
	return (SUCCESS);
}
