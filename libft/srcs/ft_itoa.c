/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:04 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:04 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_array(int n)
{
	int	size;

	size = 0;
	if (n == INT_MIN)
	{
		n /= 10;
		n *= -1;
		size += 2;
	}
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char	*case_int_min(int n)
{
	char	*tmp;

	tmp = ft_calloc(size_array(n) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = '-';
	tmp += size_array(n) - 1;
	*tmp-- = n % 10 * -1 + 48;
	n /= 10;
	n *= -1;
	while (n >= 10)
	{
		*tmp-- = n % 10 + 48;
		n /= 10;
	}
	*tmp = n + 48;
	return (tmp - 1);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		signe;

	if (n == INT_MIN)
		return (case_int_min(n));
	tmp = ft_calloc(size_array(n) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	signe = 0;
	if (n < 0)
	{
		*tmp = '-';
		signe = 1;
		n *= -1;
	}
	tmp += size_array(n) + signe - 1;
	while (n >= 10)
	{
		*tmp-- = n % 10 + 48;
		n /= 10;
	}
	*tmp = n + 48;
	return (tmp - signe);
}

/*int	main(void)
{
	printf("%s\n%d\n", ft_itoa(-2546), -2546);
	printf("%s\n%d\n", ft_itoa(2546), 2546);
	printf("%s\n%d\n", ft_itoa(0), 0);
	printf("%s\n%d\n", ft_itoa(INT_MIN), INT_MIN);
	printf("%s\n%d\n", ft_itoa(INT_MAX), INT_MAX);
}*/
