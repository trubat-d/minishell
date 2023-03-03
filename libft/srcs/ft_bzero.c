/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:48:37 by hradoux           #+#    #+#             */
/*   Updated: 2022/08/20 17:48:37 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n-- > 0)
		*str++ = '\0';
}

/*int	main(void)
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("Before memset(): %s\n", str);

    ft_bzero(str + 13, 8*sizeof(char));

	printf("After memset():  %s\n", str);
    printf("After memset()starting at str[21]:  %s\n", &str[21]);
    return 0;
}*/
