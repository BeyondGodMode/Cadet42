/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:15:55 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 14:25:15 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = (void *)malloc(total);
	if (ptr != NULL)
		ft_memset(ptr, 0, total);
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	size_t num_elements = 5;
//     size_t element_size = sizeof(int);

//     // Using the standard calloc function
//     int *array_std = (int *)calloc(num_elements, element_size);
//     if (array_std) {
//         printf("Using calloc (Standard):\n");
//         for (size_t i = 0; i < num_elements; i++) {
//             printf("%d ", array_std[i]);
//         }
//         printf("\n");
//         free(array_std);
//     }

//     // Implementing your own calloc function
//     int *array_custom = (int *)ft_calloc(num_elements, element_size);
//     if (array_custom) {
//         printf("Using ft_calloc (Custom):\n");
//         for (size_t i = 0; i < num_elements; i++) {
//             printf("%d ", array_custom[i]);
//         }
//         printf("\n");
//         free(array_custom);
//     }

//     return 0;
// }