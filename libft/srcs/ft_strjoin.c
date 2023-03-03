/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:48 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:48 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*start_tmp;

	if (!*s1 && !*s2)
	{
		tmp = ft_calloc(1, sizeof(char));
		if (!tmp)
			return (0);
		return (tmp);
	}
	tmp = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!tmp)
		return (0);
	start_tmp = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	return (start_tmp);
}

/*int	main(void)
{
	printf("'%s'\n", ft_strjoin("Bonjour_", "les_zouzous!"));
	printf("'%s'\n", ft_strjoin("", ""));
	printf("'%s'\n", ft_strjoin("", "les_zouzous!"));
}*/
