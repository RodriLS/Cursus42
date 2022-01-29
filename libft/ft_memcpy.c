/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:44:56 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 18:53:31 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	const char	*src_aux;
	char		*dest_aux;
	size_t		i;

	i = 0;
	if (src == NULL && dest == NULL && len != 0)
		return (NULL);
	src_aux = src;
	dest_aux = dest;
	while (i < len)
	{
		dest_aux[i] = src_aux[i];
		i++;
	}
	return ((void *) dest_aux);
}
