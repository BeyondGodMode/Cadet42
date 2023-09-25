/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:41:02 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/24 15:55:17 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (((unsigned char)(*s1) - (unsigned char)(*s2)));
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char str1[] = "test\200";
//     char str2[] = "test\0";
//     char str3[] = "banana";

// 	int result1 = ft_strncmp(str1, str2, 6);
// 	int result2 = ft_strncmp(str1, str3, 5);
// 	int result3 = ft_strncmp(str2, str1, 6);
// 	printf("Result 1: %d\n", result1);
// 	printf("Result 2: %d\n", result2);
// 	printf("Result 3: %d\n", result3);

// 	result1 = strncmp(str1, str2, 6);
// 	result2 = strncmp(str1, str3, 5);
// 	result3 = strncmp(str2, str1, 6);
// 	printf("Result 1: %d\n", result1);
// 	printf("Result 2: %d\n", result2);
// 	printf("Result 3: %d\n", result3);
//     return 0;
// }
