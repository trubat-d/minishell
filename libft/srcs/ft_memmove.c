/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:25 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:25 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	tmp_dest = dest;
	tmp_src = src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		tmp_dest += n - 1;
		tmp_src += n - 1;
		while (n--)
			*tmp_dest-- = *tmp_src--;
		return (dest);
	}
	else
	{
		while (n--)
		*tmp_dest++ = *tmp_src++;
		return (dest);
	}
}

/*int	main(void)
{
	char	c[6] = "hello";
	char	*c1;
	char	d[8] = "bonjour";
	char	*d1;

	c1 = c;
	d1 = d;
	c1 = ft_memmove(c1+4, d1, 5);
	//c1 = memmove(c1+4, d1, 5);
	printf("'%s' '%s'\n", c, d1);
}*/
