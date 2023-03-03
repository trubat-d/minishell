/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hradoux <hradoux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:26:38 by hradoux           #+#    #+#             */
/*   Updated: 2022/10/08 16:26:38 by hradoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*list;

	if (!lst || !f)
		return (0);
	element = ft_lstnew((*f)(lst->content));
	if (!element)
		return (0);
	list = element;
	lst = lst->next;
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (!element)
		{
			ft_lstclear(&element, (*del));
			break ;
		}
		ft_lstadd_back(&list, element);
		lst = lst->next;
	}
	return (list);
}
