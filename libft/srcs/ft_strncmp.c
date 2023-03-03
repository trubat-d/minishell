/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:00 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:00 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

/*int	main(void)
{
	char	array1[9] = "Bonjour2";
	char	array2[9] = "Bonjour3";
	char	*s1 = array1;
	char	*s2 = array2;

	printf("%d %d\n", ft_strncmp(s1, s2, 7), strncmp(s1, s2, 7));
	printf("%d %d\n", ft_strncmp(s1, s2, 8), strncmp(s1, s2, 8));
}*/
