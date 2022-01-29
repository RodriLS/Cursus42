/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:51:25 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/29 15:04:46 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*ptr;
	char	*aux;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	aux = ptr;
	while (*s1 != 0)
	{
		*aux = *s1;
		aux++;
		s1++;
	}
	while (*s2 != 0)
	{
		*aux = *s2;
		aux++;
		s2++;
	}
	*aux = 0;
	return (ptr);
}
