/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:23 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:23 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = dest;
	tmp_src = src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}

/*int	main(void)
{
	char	c[6] = "hello";
	char	*c1;
	char	d[8] = "bonjour";
	char	*d1;

	c1 = c;
	d1 = d;
	d1 = ft_memcpy(d1, c1, 5);
	printf("'%s'\n", d);
}*/
