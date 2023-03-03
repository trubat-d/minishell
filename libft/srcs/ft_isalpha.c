/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:52 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:52 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d %d %d %d %d\n", ft_isalpha('c'), ft_isalpha('C'),
		ft_isalpha(' '), ft_isalpha('!'), ft_isalpha('1'));
	return (0);
}*/
