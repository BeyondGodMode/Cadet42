/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:28:05 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/22 14:11:38 by tsongtra         ###   ########.fr       */
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
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	// char source[] = "Hello, World!";
//     // char destination[20];
// 	// char destination2[20];
//     // memmove(destination, source, sizeof(source));
//     // printf("Using memmove (Standard): %s\n", destination);
//     // ft_memmove(destination2, source, sizeof(source));
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
//     char s0[] = { 0,  0,  0,  0,  0,  0, 0};
//     char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
//     char sResult[] = {67, 68, 67, 68, 69, 0, 45};
//     char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
//     printf("Using ft_memmove (Custom): %s\n", destination2);
// 	printf("Src : %s\n", source);

//     return 0;
// }