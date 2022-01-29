/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:44:16 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 18:41:15 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	static	*ft_strdup2(const char *src, char c)
{
	char	*p;
	int		i;
	int		n;

	n = 0;
	while (*(src + n) != c && *(src + n) != 0)
		n++;
	p = malloc((n + 1) * sizeof(char));
	i = 0;
	while (i < n)
	{
		*(p + i) = *(src + i);
		i++;
	}
	*(p + i) = 0;
	return (p);
}

int	static	get_num_of_strs(const char *str, char c)
{
	int		cont;

	if (*str == 0)
		return (0);
	cont = 0;
	if (*str != c)
		cont++;
	while (*(str + 1) != 0)
	{
		if ((*(str) == c) && (*(str + 1) != c))
			cont++;
		str++;
	}
	return (cont);
}

char	**ft_split(const char *str, char c)
{
	int		cont;
	char	*aux;
	char	**p;
	int		i;

	if (str == NULL)
		return (NULL);
	cont = get_num_of_strs(str, c) + 1;
	p = malloc(cont * sizeof(char *));
	if (p == NULL)
		return (NULL);
	i = 0;
	if (*str != c && *str != 0)
		p[i++] = ft_strdup2(str, c);
	aux = (char *) str + (*str != 0);
	while (*aux != 0)
	{
		if ((*(aux - 1) == c) && (*aux != c))
			p[i++] = ft_strdup2(aux, c);
		aux++;
	}
	p[i] = 0;
	return (p);
}
