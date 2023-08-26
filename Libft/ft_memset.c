/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:05:00 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/27 02:23:08 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = ptr;
	val = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = val;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>

// int	main()
// {
// 	char str[] = "Hello, World!";
// 	printf("Before memset: %s\n", str);

// 	// Using ft_memset to set the first 5 characters to 'X'
// 	ft_memset(str, 'X', 5);
// 	printf("After memset: %s\n", str);
// 	return (0);
// }
