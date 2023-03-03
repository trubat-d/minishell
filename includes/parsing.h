/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:34:15 by jolivier          #+#    #+#             */
/*   Updated: 2023/02/19 15:05:47 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		white_space(char c);
////
int		classify(t_tree *tree, t_bash *bash);
/////
char	*ft_substr_minishell(char const *s, unsigned int start, size_t len);
/////
char	*ft_substr_brkt(char const *s, int index);
char	*ft_substr_brkt_2(char const *s, int index);
/////
int		not_alpha_num(char c);
char	*swap_var(char const *s, char **env);
char	*dup_string_parse(char const *s, char c);
char	**split_parse(char const *s, char c);
/////
int		parse_error(char *line);
char	*var_in_env(char const *s, char **env);
size_t	size_dollar_double_quote(char const **s, char **env);
size_t	var_length(char const *s, char **env);
size_t	size_dollar_no_quote(char const **s, char **env);
///////
void	ft_tolower_str(char **str);
int		is_builtin(char *cmd);

#endif