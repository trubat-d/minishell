/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivier <jolivier@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:27:04 by jolivier          #+#    #+#             */
/*   Updated: 2023/01/13 13:27:04 by jolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	ft_atoi_check(const char *str)
{
	long	signe;
	long	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++ ;
	signe = 1;
	if (*str == '-' || *str == '+')
	{
		signe = (44 - *str);
		str++;
	}
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * signe);
}

int	check_digit(char *str)
{
	int		count;

	if (ft_atoi_check(str) > INT_MAX || ft_atoi_check(str) < INT_MIN)
		return (0);
	count = 0;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			return (0);
		if ((*str == '+' || *str == '-') && count)
			return (0);
		if ((*str == '+' || *str == '-') && *(str + 1) == 0)
			return (0);
		str++;
		count++;
	}
	return (1);
}

int	ft_exit(char **args)
{
	if (args[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	if (!check_digit(args[1]))
	{
		ft_putstr_fd("exit\nnot_bash: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit (255);
	}
	if (args[2])
	{
		ft_putstr_fd("exit\nnot_bash: exit: too many arguments\n", 2);
		return (1);
	}
	else
	{
		printf("exit\n");
		exit(ft_atoi(args[1]) % 256);
	}
}
