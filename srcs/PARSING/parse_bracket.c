/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bracket.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:42:10 by hradoux           #+#    #+#             */
/*   Updated: 2023/02/08 18:42:13 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*				FT_SUBSTR_MINISHELL
 *
 * 	Comme celle de libft avec la rajout de trim_ws.
 */

size_t	define_size_2(char const *s, unsigned int index)
{
	int		i;
	int		cnt;
	size_t	size;
	int		quote;

	size = 0;
	s += index;
	i = -1;
	quote = 0;
	cnt = 0;
	while (*(s + (++i)))
	{
		if (!white_space(*(s + i)) && (*(s + i)) != '<' && (*(s + i)) != '>')
			cnt++;
		if ((*(s + i) == 39 || *(s + i) == 34)
			&& (!quote || quote == *(s + i)))
			quote = (quote - *(s + i)) * -1;
		if ((white_space(*(s + i)) && !quote && cnt)
			|| (((*(s + i)) == '<' || (*(s + i)) == '>') && !quote && cnt))
			break ;
		if (!white_space(*(s + i)))
			size++;
	}
	return (size);
}

size_t	define_size(char const *s, unsigned int index)
{
	int		i;
	int		cnt;
	int		quote;
	size_t	size;

	size = ft_strlen(s);
	s += index;
	i = -1;
	quote = 0;
	cnt = 0;
	while (*(s + (++i)))
	{
		if (!white_space(*(s + i)) && (*(s + i)) != '<' && (*(s + i)) != '>')
			cnt++;
		if ((*(s + i) == 39 || *(s + i) == 34)
			&& (!quote || quote == *(s + i)))
			quote = (quote - *(s + i)) * -1;
		if ((white_space(*(s + i)) && !quote && cnt)
			|| (((*(s + i)) == '<' || (*(s + i)) == '>') && !quote && cnt))
			break ;
		else
			size--;
	}
	return (size);
}

void	trim_brkt(char const *s, char *tmp, int *j, int *i)
{
	int	cnt;
	int	quote;

	cnt = 0;
	quote = 0;
	while (*(s + *i))
	{
		if (!white_space(*(s + *i)) && (*(s + *i)) != '<' && (*(s + *i)) != '>')
			cnt++;
		if ((*(s + *i) == 39 || *(s + *i) == 34)
			&& (!quote || quote == *(s + *i)))
			quote = (quote - *(s + *i)) * -1;
		if ((white_space(*(s + *i)) && !quote && cnt)
			|| (((*(s + *i)) == '<' || (*(s + *i)) == '>') && !quote && cnt))
		{
			*(tmp + (*j)++) = *(s + *i);
			break ;
		}
		(*i)++;
	}
}

char	*ft_substr_brkt(char const *s, int index)
{
	int		i;
	int		j;
	char	*tmp;
	size_t	size_s;

	size_s = define_size(s, index);
	tmp = ft_calloc(size_s + 1, sizeof(char));
	i = -1;
	j = 0;
	while (*(s + (++i)) && size_s--)
	{
		if (i != index)
			*(tmp + j++) = *(s + i);
		else
			trim_brkt(s, tmp, &j, &i);
	}
	return (tmp);
}

char	*ft_substr_brkt_2(char const *s, int index)
{
	int		i;
	int		j;
	char	*tmp;
	size_t	size_s;

	size_s = define_size_2(s, index);
	tmp = ft_calloc(size_s + 1, sizeof(char));
	i = 0;
	j = 0;
	s += index;
	while (size_s--)
	{
		if (!white_space(*(s + i)))
			*(tmp + (j++)) = *(s + i);
		else
			size_s++;
		i++;
	}
	return (tmp);
}
