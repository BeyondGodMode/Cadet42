/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:28:19 by tsongtra          #+#    #+#             */
/*   Updated: 2025/03/04 11:58:23 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_pointer(unsigned long n)
{
	size_t	length;

	length = 0;
	length += 2;
	write(1, "0x", 2);
	length += print_hex(n, 'x');
	return (length);
}
