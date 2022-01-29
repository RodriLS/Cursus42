/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:12:57 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/23 19:03:38 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*init;

	init = str;
	while (*str != 0)
		str++;
	if (c == 0)
		return ((char *) str);
	str--;
	while (str != init - 1 && *str != (char) c)
		str--;
	if (str == init - 1)
		return (NULL);
	return ((char *) str);
}
