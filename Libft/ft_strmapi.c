/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:26:38 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/24 13:49:05 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*res;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	res = str;
	while (*s != '\0')
		*str++ = f(i++, *s++);
	*str = '\0';
	return (res);
}

// #include <stdio.h>

// char	to_upper(unsigned int index, char c)
// {
// 	return (c - 32);
// }

// int	main()
// {
// 	const char *input = "hello";
// 	char *result = ft_strmapi(input, to_upper);

// 	if (result)
// 	{
// 		printf("Input: %s\n", input);
// 		printf("Mapped Result: %s\n", result);
// 		// Don't forget to free the memory allocated by ft_strmapi
// 		free(result);
//     }
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }
