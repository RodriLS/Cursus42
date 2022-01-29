/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:07:22 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 17:43:37 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static void	store_digit(char *init, char *s, int n)
{
	while (s >= init)
	{
		*s = (n % 10) * (-2 * (n < 0) + 1) + '0';
		n /= 10;
		s--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;
	int		aux;

	aux = n;
	i = 0;
	if (n == 0)
		i = 1;
	while (aux != 0)
	{
		aux /= 10;
		i++;
	}
	i += (n < 0);
	ptr = malloc(i * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = 0;
	i--;
	if (n < 0)
		ptr[0] = '-';
	store_digit(ptr + (n < 0), ptr + i, n);
	return (ptr);
}
