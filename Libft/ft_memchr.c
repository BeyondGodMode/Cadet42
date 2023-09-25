/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:19:38 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/25 11:43:24 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)(unsigned char *)s - 1);
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	const char memory_block[] = {10, 20, 30, 40, 50};
// 	int target = 40;
// 	size_t size = sizeof(memory_block);

//     // Using the standard memchr function
//     // void *result_std = memchr(((void *)0), '\0', 0x20);
// 	void *result_std2 = ft_memchr(((void *)0), '\0', 0x20);

// 	// printf("Ori = %ld\n",(const char *)result_std - memory_block);
// 	printf("ft = %ld\n",(const char *)result_std2 - memory_block);
// 	return (0);
// }