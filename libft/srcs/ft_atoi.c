/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:34 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:34 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++ ;
	signe = 1;
	if (*str == '-' || *str == '+')
	{
		signe = (44 - *str);
		str++;
	}
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * signe);
}

/*int	main(void)
{
	printf("me: %d\nft: %d\n",  ft_atoi("	 -2569"), atoi("	 -2569"));
	printf("me: %d\nft: %d\n",  ft_atoi("	 -2147483648"), atoi("	 -2147483648"));
	printf("me: %d\nft: %d\n",  ft_atoi("	 0"), atoi("	 0"));
	printf("me: %d\nft: %d\n",  ft_atoi("	 2147483647"), atoi("	 2147483647"));
	printf("me: %d\nft: %d\n",  ft_atoi("	 +147483647"), atoi("	 +147483647"));
	printf("me: %d\nft: %d\n",  ft_atoi("	 14748364"), atoi("	 14748364"));
}*/
