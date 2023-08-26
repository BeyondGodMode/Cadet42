/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:28:05 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 14:04:25 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char source[] = "Hello, World!";
//     char destination[20];
// 	char destination2[20];
	
//     memmove(destination, source, sizeof(source));
//     printf("Using memmove (Standard): %s\n", destination);
//     ft_memmove(destination2, source, sizeof(source));

//     printf("Using ft_memmove (Custom): %s\n", destination2);
// 	printf("Src : %s\n", source);

//     return 0;
// }