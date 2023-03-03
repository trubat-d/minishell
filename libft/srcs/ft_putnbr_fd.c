/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:40:36 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:40:36 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write (fd, "-", 1);
		if (n == -2147483648)
		{	
			write (fd, "2147483648", 10);
			return ;
		}
		else
			n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
	{
		c = n + 48;
		write (fd, &c, 1);
	}	
}

/*int	main(void)
{
	int	fd = open("test.txt", O_WRONLY);

	ft_putnbr_fd(INT_MIN, fd);
	ft_putendl_fd("\n-2147483648", fd);
	close (fd);
}*/