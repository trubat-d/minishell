/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:05 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:05 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	s += size;
	while (size-- >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

/*int	main(void)
{
	char 	str[8] = "Bonjour\0";
	char	*ptr = str;

	printf ("'%s' '%s'\n", ft_strrchr(ptr, 'o'), strrchr(ptr, 'o'));
}*/
