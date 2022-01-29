/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:58:26 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/23 19:11:15 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*pd;
	const char	*ps;

	pd = dest;
	ps = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (ps < pd && pd < ps + len)
	{
		while (len-- > 0)
			pd[len] = ps[len];
	}
	else
	{
		while (len > 0)
		{
			*pd++ = *ps++;
			len--;
		}
	}
	return (dest);
}
