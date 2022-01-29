/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:27 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 17:35:13 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;
	int		n;

	n = 0;
	while (*(src + n) != 0)
		n++;
	p = malloc((n + 1) * sizeof(*p));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(p + i) = *(src + i);
		i++;
	}
	p[i] = 0;
	return (p);
}
