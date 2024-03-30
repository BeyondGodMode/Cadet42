/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:57 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/21 12:54:57 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char buffer[10] = "Hello";
// 	char buffer2[10] = "Hello";
//     // Using the standard bzero (memset with zero) function
//     bzero(buffer, sizeof(buffer));
//     printf("Using bzero (Standard): %s\n", buffer);
//     // Implementing your own bzero function
//     ft_bzero(buffer2, sizeof(buffer2));
//     printf("Using ft_bzero (Custom): %s\n", buffer2);
//     return 0;
// }