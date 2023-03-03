/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:01 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:01 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*#include <ctype.h>

int	main(void)
{
	printf("%d %d %d %d %d\n", ft_isprint('c'), ft_isprint(' '),
		ft_isprint('\n'), ft_isprint('\t'), ft_isprint('	'));
	printf("%d %d %d %d %d\n", isprint('C'), isprint(' '),
		isprint('\n'), isprint('\t'), isprint('	'));
	return (0);
}*/
