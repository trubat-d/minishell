/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:27:41 by hradoux           #+#    #+#             */
/*   Updated: 2022/08/26 23:27:41 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	cat_length;
	size_t	tot_length;

	cat_length = size - ft_strlen(dest) - 1;
	tot_length = ft_strlen(dest) + ft_strlen(src);
	if (size == 0 || size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	dest += ft_strlen(dest);
	while (*src && cat_length--)
		*dest++ = *src++;
	*dest = 0;
	return (tot_length);
}

/*int	main(void)
{
	char	src [15] = "Born_to_code";
	char	dest [40] = "Viva La Vida_";

	printf ("ft_:	%lu, '%s'\n", ft_strlcat(dest, src, 30), dest);
	//printf ("ft_:	%lu, '%s'\n", strlcat(dest, src, 20), dest);
	return (0);
}*/
