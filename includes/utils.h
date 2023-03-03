/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:59 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/14 17:23:59 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//SIGNAL
void	set_signal(int option);
void	tty_attribute(int option);
void	rl_replace_line(const char *text, int clear_undo);

//ENV
char	*get_env(char *name, char **env);
char	**ft_tabdup(char **tab);
int		ft_strcmp(const char *s1, const char *s2);

//PATH
char	*get_path_cmd(char *command, char **env);
//////
int		full_white_space(char *line);
//////
int		tab_size(char **tab);

#endif