/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:55 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:55 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d %d %d %d %d\n", ft_isascii('c'), ft_isascii('C'),
		ft_isascii(' '), ft_isascii('!'), ft_isascii(128));
	return (0);
}*/
