/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:17 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:17 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	tmp_c;

	tmp_src = (unsigned char *)s;
	tmp_c = (unsigned char )c;
	while (n--)
	{
		if (*tmp_src == tmp_c)
			return (tmp_src);
		tmp_src++;
	}
	return (0);
}

//Both c and the bytes of the memory area
//pointed to by s are interpreted as unsigned char.

/*int	main(void)
{
	char	c[6] = "hello";
	char	*c1;

	c1 = c;
	c1 = ft_memchr(c, 'l', 2);
	//c1 = memchr(c, 'l', 2);
	printf("'%s' '%s'\n", c1, c);
}*/
