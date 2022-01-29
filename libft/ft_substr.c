/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:38:33 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 18:28:15 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	static	*return_empty(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (ptr == NULL)
		return (NULL);
	*ptr = 0;
	return (ptr);
}

static	char	*strdup2(const char *init, const char *end)
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

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	while (start != 0 && *str != 0)
	{
		str++;
		start--;
	}
	if (*str == 0 || len == 0)
		return (return_empty());
	i = 0;
	while (i < len && str[i] != 0)
		i++;
	return (strdup2(str, str + i));
}
