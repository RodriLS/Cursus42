/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:11:57 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 18:31:49 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s2 = ft_strdup(s);
	if (s2 == NULL)
		return (NULL);
	while (s2[i] != 0)
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	return (s2);
}
