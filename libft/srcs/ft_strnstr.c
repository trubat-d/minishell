/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:02 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:02 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	size_needle;
	size_t	size_check;

	size_needle = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (size-- && *haystack)
	{
		size_check = 0;
		while (*haystack == *needle && *needle && size_check <= size)
		{
			size_check++;
			haystack++;
			needle++;
		}
		if (size_check == size_needle)
			return ((char *)(haystack - size_check));
		haystack -= size_check - 1;
		needle -= size_check;
	}
	return (0);
}

/*int	main(void)
{
	char	str[8] = "Bonjour";
	char	str2[4] = "our";
	char	*haystack = str;
	char	*needle = str2;

	printf ("'%s'\n", ft_strnstr(haystack, needle, 6));
	printf ("'%s'\n", ft_strnstr(haystack, needle, 7));
	printf ("'%s'\n", ft_strnstr(haystack, "on", 3));
	printf ("'%s'\n", ft_strnstr(haystack, "on", 2));
}*/
