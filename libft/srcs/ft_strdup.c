/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:46 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:46 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*tmp;

	size_s = ft_strlen(s);
	tmp = ft_calloc(size_s + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (*s)
		*tmp++ = *s++;
	tmp -= size_s;
	return (tmp);
}

/*int	main(void)
{
	char	s[8] = "Bonjour";
	printf ("%s\n", ft_strdup(s));
}*/
