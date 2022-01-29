/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:10:41 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/23 19:07:31 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	aux;

	aux = (char) c;
	while (*str != 0 && *str != (char) c)
		str++;
	if ((*str == 0 && aux == 0) || (*str != 0))
		return ((char *) str);
	return (NULL);
}
