/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:55:38 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/24 15:30:02 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb <= -10)
	{
		ft_putnbr_fd(nb / -10, fd);
		nb = nb % -10;
	}
	if (nb < 10)
	{
		if (nb < 0)
			nb = -nb;
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}

// int	main()
// {
// 	ft_putnbr_fd(-5, 2);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	return (0);
// }
