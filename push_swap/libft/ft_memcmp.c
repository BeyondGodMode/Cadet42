/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:14:18 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 13:26:32 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	const char block1[] = "Hello, World!";
//     const char block2[] = "Hello, World!";
//     size_t size = sizeof(block1);

//     // Using the standard memcmp function
//     int result_std = memcmp(block1, block2, size);

//     if (result_std < 0) {
//         printf("Using memcmp (Standard): block1 is less than block2\n");
//     } else if (result_std > 0) {
//         printf("Using memcmp (Standard): block1 is greater than block2\n");
//     } else {
//         printf("Using memcmp (Standard): block1 is equal to block2\n");
//     }

//     // Implementing your own memcmp function
//     int result_custom = ft_memcmp(block1, block2, size);

//     if (result_custom < 0) {
//         printf("Using ft_memcmp (Custom): block1 is less than block2\n");
//     } else if (result_custom > 0) {
//         printf("Using ft_memcmp (Custom): block1 is greater than block2\n");
//     } else {
//         printf("Using ft_memcmp (Custom): block1 is equal to block2\n");
//     }

//     return 0;
// }