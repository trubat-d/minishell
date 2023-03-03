/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:28:31 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/19 18:28:38 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*new_path(char *tab, char *command)
{
	char	*tmp;
	char	*tmp_start;

	tmp = ft_calloc(ft_strlen(tab) + \
	ft_strlen(command) + 2, sizeof(char));
	tmp_start = tmp;
	while (*tab)
		*tmp++ = *tab++;
	*tmp++ = '/';
	while (*command)
		*tmp++ = *command++;
	return (tmp_start);
}

char	*ft_all_path_line(char **env)
{
	while (*env)
	{
		if (!ft_memcmp(*env, "PATH=", 5))
			return (ft_strtrim(*env, "PATH="));
		env++;
	}
	return (NULL);
}

char	**all_paths(char *command, char **env)
{
	int		i;
	char	*path;
	char	**access;
	char	**path_split;

	path = ft_all_path_line(env);
	if (path)
	{
		path_split = ft_split(path, ':');
		free(path);
		access = ft_calloc(tab_size(path_split) + 1, sizeof(char *));
		i = -1;
		while (path_split[++i])
			access[i] = new_path(path_split[i], command);
		free_tab(path_split);
	}
	else
	{
		access = ft_calloc(2, sizeof(char *));
		*access = new_path(".", command);
		*(access + 1) = NULL;
	}
	return (access);
}

char	*define_path(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*(paths + i))
	{
		if (!access(*(paths + i), R_OK | F_OK))
		{
			tmp = ft_strdup(*(paths + i));
			free_tab(paths);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

/*if (!access(command, R_OK | X_OK | F_OK))
	return (ft_strdup(command));*/
char	*get_path_cmd(char *command, char **env)
{
	char	*tmp;
	char	**paths;

	if (!ft_strncmp(command, ".//", 2) || !ft_strncmp(command, "//", 1))
		return (dup_string_parse(command, ' '));
	paths = all_paths(command, env);
	tmp = define_path(paths);
	if (tmp)
		return (tmp);
	free_tab(paths);
	return (NULL);
}
