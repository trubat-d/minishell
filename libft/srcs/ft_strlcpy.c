/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:53 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:53 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	size_src;

	size_src = ft_strlen(src);
	if (size)
	{
		size--;
		while (size-- && *src)
			*dest++ = *src++;
		*dest = 0;
	}
	return (size_src);
}

/*int	main(void)
{
	const char	src[9] = "Bonjour";
	char		dest[25] = "Au revoiz les zouzous";

	printf("%lu '%s' '%s'\n", ft_strlcpy(dest, src, 46), dest, dest + 8);
}*/
