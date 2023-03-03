/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:16:47 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 08:16:47 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_line(t_bash *bash)
{
	bash->input = NULL;
	bash->input = readline("not_bash$ ");
	if (bash->input && *bash->input)
		add_history(bash->input);
}

void	ft_levelup(t_bash *bash)
{
	int		i;
	int		value;
	char	*tmp;
	char	*env_line;
	char	*tmp_itoa;

	i = 0;
	while (bash->env[i])
	{
		if (!ft_memcmp(bash->env[i], "SHLVL=", 6))
		{
			env_line = (ft_strtrim(bash->env[i], "SHLVL="));
			value = ft_atoi(env_line) + 1;
			tmp_itoa = ft_itoa(value);
			tmp = ft_strjoin("SHLVL=", tmp_itoa);
			free(env_line);
			free(tmp_itoa);
			free(bash->env[i]);
			bash->env[i] = tmp;
			return ;
		}
		i++;
	}
}

void	init_bash(t_bash *bash, char **envp)
{
	bash->pid = 0;
	g_bash.status = 0;
	bash->env = ft_tabdup(envp);
	ft_levelup(bash);
}

void	exec_prompt(t_bash	*bash, t_tree	*tree)
{
	if (!bash->parse_err)
	{
		bash->in_fd = 0;
		bash->out_fd = 1;
		bash->hrdc = 0;
		set_signal(0);
		exec_tree(tree, bash);
		close(bash->tmp_fd);
	}
	free_tree(tree);
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*tree;
	t_bash	bash;

	(void)argc;
	(void)argv;
	init_bash(&bash, envp);
	while (1)
	{
		tree = NULL;
		bash.parse_err = 0;
		bash.tmp_fd = dup(STDIN_FILENO);
		tty_attribute(1);
		set_signal(1);
		get_line(&bash);
		if (!bash.input)
		{
			tty_attribute(0);
			exit(0);
		}
		if (*bash.input && full_white_space(bash.input) \
		&& !parse_error(bash.input))
			tree = create_tree(bash.input, NULL);
		if (tree)
			exec_prompt(&bash, tree);
	}
}

/*if (argc == 3 && !ft_strcmp(argv[1], "-c"))
{
	init_bash(&bash, envp);
	tree = NULL;
	g_parse_err = 0;
	bash.tmp_fd = dup(STDIN_FILENO);
	tty_attribute(1);
	set_signal(1);
	bash.input = ft_strdup(argv[2]);
	if (!bash.input)
	{
		tty_attribute(0);
		exit(0);
	}
	if (*bash.input && !parse_error(bash.input))
		tree = create_tree(bash.input, NULL);
	if (tree && !g_parse_err)
	{
		bash.in_fd = 0;
		bash.out_fd = 1;
		bash.hrdc = 0;
		set_signal(0);
		exec_tree(tree, &bash);
		close(bash.tmp_fd);
		free_tree(tree);
	}
	exit(g_bash.status);
}*/