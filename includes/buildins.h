/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:20:52 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/14 09:20:52 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDINS_H
# define BUILDINS_H

int		ft_cd(char **path, t_bash *bash);
int		ft_echo(char **args, t_bash *bash);
int		ft_env(t_bash *bash);
int		ft_exit(char **args);
int		ft_pwd(void);
int		ft_unset(char **args, t_bash *bash, int status);
void	set_env(char *name, char *value, char **env);
int		ft_export(t_bash *bash, char **args);
int		arg_exists(char **env, char *arg);
char	**ft_add_env_arg(char **env, char *arg, int incr[3], char **tab);
char	**ft_add_env(char **env, char *arg);

#endif
