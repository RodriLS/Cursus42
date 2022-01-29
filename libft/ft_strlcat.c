/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:47:35 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/29 17:28:18 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	static	ft_calculate_result(size_t i, size_t size, const char *src)
{
	size_t	j;

	if (i < size)
		j = i;
	else
		j = size;
	while (*src != 0)
	{
		j++;
		src++;
	}
	return (j);
}

unsigned long	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*dest != 0 && i < size)
	{
		dest++;
		i++;
	}
	j = ft_calculate_result(i, size, src);
	while (*src != 0 && i + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
		*dest = 0;
	return (j);
}
