/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:06 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:06 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	tmp_src = src;
	tmp_dest = dest;
	while (n--)
	{
		*tmp_dest++ = *tmp_src;
		if (*tmp_src++ == c)
			return (tmp_dest);
	}
	return (0);
}

/*int	main(void)
{
	char	c[6] = "hello";
	char	*c1;
	char	d[8] = "bonjour";
	char	*d1;

	c1 = c;
	d1 = d;
	//d1 = ft_memccpy(d1, c1, 'e', 5);
	d1 = memccpy(d1, c1, 'e', 5);
	printf("'%s' '%s'\n", d1, d);
}*/
