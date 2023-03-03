/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:58 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:58 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d %d %d %d %d\n", ft_isdigit('c'), ft_isdigit('C'),
		ft_isdigit(' '), ft_isdigit('!'), ft_isdigit('1'));
	return (0);
}*/
