/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:56:41 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 12:07:57 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	const char source[] = "Hello, World!";
//     char destination[20];
// 	char destination2[20];

//     memcpy(destination, source, sizeof(source));
//     printf("Ori : %s\n", destination);
//     ft_memcpy(destination2, source, sizeof(source));
//     printf("ft : %s\n", destination2);

//     return 0;
// }