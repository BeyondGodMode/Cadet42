/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:01:05 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/21 12:43:57 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *) stack);
	needle_len = ft_strlen(needle);
	if (len == 0)
		return (NULL);
	if (needle_len == 0)
		return ((char *)stack);
	i = 0;
	while (i <= len - needle_len && stack[i] != '\0')
	{
		if (ft_strncmp(stack + i, needle, needle_len) == 0)
			return ((char *)(stack + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *haystack = "Hello, World! This is a test.";
//     const char *needle = "orld";
//     size_t max_len = 20;

//     char *result = ft_strnstr(haystack, needle, max_len);
// 	char *result2 = strnstr(haystack, needle, max_len);
// 	printf("Result : %s\n", result);
// 	printf("Result : %s\n", result2);
// 	return (0);
// }
