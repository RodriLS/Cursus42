/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:15:55 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/29 13:12:06 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	if (lst == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
		return (NULL);
	aux = res;
	lst = lst->next;
	while (lst != NULL)
	{
		res->next = ft_lstnew(f(lst->content));
		res = res->next;
		if (res == NULL)
		{
			ft_lstclear(&res, del);
			return (aux);
		}
		lst = lst->next;
	}
	return (aux);
}
