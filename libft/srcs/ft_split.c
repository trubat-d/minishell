/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:41 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:41 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != c)
			s++;
	}
	return (word_count);
}

int	string_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

char	*dup_string(char const *s, char c)
{
	char	*tmp;
	char	*tmp_start;

	tmp = ft_calloc(string_size(s, c) + 1, sizeof(char));
	if (!tmp)
		return (0);
	tmp_start = tmp;
	while (*s && *s != c)
		*tmp++ = *s++;
	return (tmp_start);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**tmp;

	word_count = ft_word_count(s, c);
	tmp = ft_calloc(word_count + 1, sizeof(char *));
	if (!tmp)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			*tmp++ = dup_string(s, c);
		while (*s && *s != c)
			s++;
	}
	tmp -= word_count;
	return (tmp);
}

/*int	main(void)
{
	char	str0[35] = "zBonjourzLeszLouslousz!z";
	char	str1[35] = "zBonjourLesLouslous!z";
	char	str2[35] = "";
	char	**tmp;

	tmp = ft_split(str0, 'z');
	while (*tmp)
		printf("test1:	'%s'\n", *tmp++);
	printf("test1:	'%s'\n", *tmp);

	tmp = ft_split(str1, 'z');
	while (*tmp)
		printf("test2:	'%s'\n", *tmp++);
	printf("test2:	'%s'\n", *tmp);

	tmp = ft_split(str2, 'z');
	while (*tmp)
		printf("test3:	'%s'\n", *tmp++);
	printf("test3:	'%s'\n", *tmp);
}*/
