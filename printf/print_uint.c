/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:31:46 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/25 11:37:11 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd(unsigned int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}

static size_t	num_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

size_t	print_uint(unsigned int n)
{
	size_t	length;

	length = num_len(n);
	ft_putnbr_fd(n, 1);
	return (length);
}
