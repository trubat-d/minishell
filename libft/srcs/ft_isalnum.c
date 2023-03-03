/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:49 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:49 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d %d %d %d %d\n", ft_isalnum('c'), ft_isalnum('C'),
		ft_isalnum(' '), ft_isalnum('!'), ft_isalnum('1'));
	return (0);
}*/
