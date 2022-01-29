/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:47:57 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 17:50:16 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 != 0 && *s2 != 0 && (unsigned char) *s1 == (unsigned char) *s2
		&& i < n)
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
		i++;
	}
	if (i < n)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else
		return ((unsigned char) *(s1 - 1) - (unsigned char) *(s2 - 1));
}
