/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:39:45 by hradoux           #+#    #+#             */
/*   Updated: 2022/09/02 23:39:45 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_alloc_error(void)
{
	ft_putstr_fd("not_bash: Malloc error!", 2);
	exit(42);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (ULONG_MAX / nmemb < size || nmemb == 0 || size == 0)
		return (NULL);
	tmp = malloc (nmemb * size);
	if (!tmp)
		ft_exit_alloc_error();
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}
