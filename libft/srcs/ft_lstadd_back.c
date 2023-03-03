/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:20:44 by hradoux           #+#    #+#             */
/*   Updated: 2022/10/08 15:20:44 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
}
