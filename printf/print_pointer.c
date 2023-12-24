/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:28:19 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/24 22:24:26 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_pointer(unsigned long n)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		length += 2;
		write(1, "0x", 2);
		length += print_hex(n, 'x');
	}
	return (length);
}
