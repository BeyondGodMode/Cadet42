/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:01:05 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/25 22:23:15 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	needle_len;
	int		i;
	int		j;

	if (*needle == '\0')
		return ((char *) stack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (i < needle_len && stack[i] != '\0')
	{
		if (i + needle_len > len)
			break ;
		j = 0;
		while (stack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(stack + i));
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
    const char *haystack = "Hello, World! This is a test.";
    const char *needle = "World";
    size_t max_len = 20;

    char *result = ft_strnstr(haystack, needle, max_len);

    if (result)
	{
		printf("Needle found: %s\n", result);
	}
	else
	{
		printf("Needle not found.\n");
	}
	return 0;
}