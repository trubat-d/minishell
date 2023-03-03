/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:15 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:15 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*#include <ctype.h>

int	main(void)
{
	printf("me: %d %d %d %d %d\n", ft_toupper('c'), ft_toupper(' '),
		ft_toupper('\n'), ft_toupper('\t'), ft_toupper('C'));
	printf("ft: %d %d %d %d %d\n", toupper('c'), toupper(' '),
		toupper('\n'), toupper('\t'), toupper('C'));
	return (0);
}*/
