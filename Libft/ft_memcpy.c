/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:56:41 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/15 12:18:49 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
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

//     // memcpy(((void *)0), "segfaulter tu dois", 0x20);
//     // printf("Ori : %s\n", destination);
//     ft_memcpy(((void *)0), "segfaulter tu dois", 0x20);
//     printf("ft : %s\n", destination2);

//     return 0;
// }