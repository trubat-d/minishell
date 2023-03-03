/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:57 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:57 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;

	tmp = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s)
		*tmp++ = (*f)(i++, *s++);
	return (tmp - i);
}

/*char	merdouille(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	printf("0123456789\n%s\n", ft_strmapi("0123456789", &merdouille));
}*/
