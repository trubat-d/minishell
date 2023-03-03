/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:12 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:12 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*#include <ctype.h>

int	main(void)
{
	printf("me: %d %d %d %d %d\n", ft_tolower('C'), ft_tolower(' '),
		ft_tolower('\n'), ft_tolower('\t'), ft_tolower('c'));
	printf("ft: %d %d %d %d %d\n", tolower('C'), tolower(' '),
		tolower('\n'), tolower('\t'), tolower('c'));
	return (0);
}*/
