/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:10 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:10 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	char	*tmp;
	char	*start_tmp;

	size_s = ft_strlen(s);
	if (start >= size_s)
	{
		tmp = ft_calloc(1, sizeof(char));
		if (!tmp)
			return (0);
		return (tmp);
	}
	if (size_s - start < len)
		tmp = ft_calloc(size_s - start + 1, sizeof(char));
	else
		tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (0);
	start_tmp = tmp;
	s += start;
	while (*s && len--)
		*tmp++ = *s++;
	return (start_tmp);
}

/*int	main(void)
{
	printf("%s\n", ft_substr("abcdefghijkl", 7, 5));
	printf("%s\n", ft_substr("abcdefghijkl", 8, 5));
	printf("%s\n", ft_substr("abcdefghijkl", 2, 5));
	printf("'%s'\n", ft_substr("abcdefghijkl", 12, 5));
	printf("'%s'\n", ft_substr("", 5, 5));
}*/
