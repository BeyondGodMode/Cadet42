/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:08:36 by tsongtra          #+#    #+#             */
/*   Updated: 2025/03/04 11:58:54 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_string(char *str)
{
	size_t	length;

	if (str == NULL)
		return (write(1, "(null)", 6));
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}
