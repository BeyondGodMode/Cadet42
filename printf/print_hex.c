/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:22:35 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/24 22:22:59 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned int c)
{
	write(1, &c, 1);
}

static void	print_hexp(unsigned long n, unsigned int c, size_t *length)
{
	if (n >= 16)
	{
		print_hexp(n / 16, c, length);
		print_hexp(n % 16, c, length);
	}
	else
	{
		if (n <= 9)
		{
			put_hex(n + '0');
			*length = *length + 1;
		}
		else
		{
			if (c == 'x')
			{
				put_hex(n - 10 + 'a');
			}
			else if (c == 'X')
			{
				put_hex(n - 10 + 'A');
			}
			*length = *length + 1;
		}
	}
}

size_t	print_hex(unsigned long n, unsigned int c)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		print_hexp(n, c, &length);
	return (length);
}
