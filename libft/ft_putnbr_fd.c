/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:55:41 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/23 19:08:57 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd);
static void	print_number(int digits[20], int fd);
static int	ft_special_cases(int nb, int fd);

void	ft_putnbr_fd(int nb, int fd)
{
	int	digits[20];
	int	i;
	int	aux;

	if (ft_special_cases(nb, fd))
		return ;
	i = 19;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	aux = nb;
	while (i > -1)
	{
		digits[i] = aux % 10;
		aux = aux / 10;
		i = i - 1;
	}
	print_number(digits, fd);
}

static int	ft_special_cases(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

static void	print_number(int digits[20], int fd)
{
	int	i;
	int	aux;
	int	b;

	b = 0;
	i = 0;
	while (i < 20)
	{
		if (digits[i] > 0 || b != 0)
		{
			b = 1;
			aux = digits[i] + 48;
			write(fd, &aux, 1);
		}
		i = i + 1;
	}
}
