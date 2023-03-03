/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:19 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:19 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}

//The memcmp() function compares the first n
//bytes (each interpreted as unsigned char) of the memory areas s1 and s2.

/*int	main(void)
{
	char	c[10] = "he2llo";
	char	*c1;
	char	d[10] = "hello";
	char	*d1;

	c1 = c;
	d1 = d;
	printf("'%d' '%d'\n", ft_memcmp(c1, d1, 5), memcmp(c1, d1, 5));
}*/
