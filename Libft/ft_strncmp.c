/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:41:02 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/25 18:58:15 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char str1[] = "apple";
//     char str2[] = "applet";
//     char str3[] = "banana";

// 	int result1 = ft_strncmp(str1, str2, 4);
// 	int result2 = ft_strncmp(str1, str3, 5);
// 	int result3 = ft_strncmp(str2, str1, 6);
// 	printf("Result 1: %d\n", result1);
// 	printf("Result 2: %d\n", result2);
// 	printf("Result 3: %d\n", result3);

// 	result1 = strncmp(str1, str2, 4);
// 	result2 = ft_strncmp(str1, str3, 5);
// 	result3 = ft_strncmp(str2, str1, 6);
// 	printf("Result 1: %d\n", result1);
// 	printf("Result 2: %d\n", result2);
// 	printf("Result 3: %d\n", result3);
//     return 0;
// }

