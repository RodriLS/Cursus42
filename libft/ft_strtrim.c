/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:51:19 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/02/06 15:05:39 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char c, const char *set)
{
	while (*set != 0)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_strdup2(const char *init, const char *end)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = 0;
	while (init + len < end)
		len++;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (len > i)
	{
		ptr[i] = init[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*init;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	init = s1;
	end = s1;
	while (is_in_set(*init, set))
		init++;
	while (*end)
		end++;
	end--;
	while (is_in_set(*end, set) && end >= init)
		end--;
	end++;
	return (ft_strdup2((char *) init, (char *) end));
}	
