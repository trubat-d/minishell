/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:41:07 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:41:07 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_trim(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

int	count_trim(char const *s1, char const *set, int *trim_start, int *trim_end)
{
	int			size;
	char const	*end_str;

	size = ft_strlen(s1);
	end_str = (s1 + ft_strlen(s1) - 1);
	while (check_trim(*s1, set) && *s1++)
		*trim_start += 1;
	while (check_trim(*end_str, set) && *end_str--)
		*trim_end += 1;
	return (*trim_start + *trim_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size_tot;
	int		trim_start;
	int		trim_end;
	char	*tmp;

	trim_start = 0;
	trim_end = 0;
	size_tot = ft_strlen(s1) - count_trim(s1, set, &trim_start, &trim_end);
	if (size_tot == 0)
	{
		tmp = ft_calloc(1, sizeof(char));
		if (!tmp)
			return (0);
		return (tmp);
	}
	tmp = ft_substr(s1, trim_start, size_tot);
	return (tmp);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("2Bonjour!", "sdfgh"));
	printf("%s\n", ft_strtrim("2Bonjour!", "2Bor!"));
	printf("%s\n", ft_strtrim("2Bonjour!", "!"));
	printf("%s\n", ft_strtrim("2Bonjour!", "!2"));
	printf("'%s'\n", ft_strtrim("2!", "!2"));
}*/