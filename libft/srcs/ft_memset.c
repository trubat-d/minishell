/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:28 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:28 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = s;
	while (n-- > 0)
		*tmp++ = c;
	return (s);
}

/*int	main(void)
{
	char	c[6];
	char	*c1;

	c1 = c;
	c1 = ft_memset(c1, 'c', 5);
	printf("'%s'\n", c);
}*/
