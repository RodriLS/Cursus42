/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:43:18 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/23 19:05:02 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	aux;
	size_t	cont;

	cont = 0;
	if (len == 0 && *needle != 0)
		return (NULL);
	if (*needle == 0)
		return ((char *) haystack);
	while (*haystack != 0 && cont < len)
	{
		aux = 0;
		while (haystack[aux] != 0 && needle[aux] != 0
			&& haystack[aux] == needle[aux] && aux < len - cont)
			aux++;
		if (needle[aux] == 0)
			return ((char *) haystack);
		haystack++;
		cont++;
	}
	return (NULL);
}
