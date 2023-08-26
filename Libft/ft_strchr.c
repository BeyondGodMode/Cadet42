/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:06:01 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 09:55:00 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *string = "Hello, World!";
//     char target = 'W';
//     char *result_std = strchr(string, target);
// 	char *result_std2 = ft_strchr(string, target);

// 	printf("Ori = %s\n",result_std);
// 	printf("ft = %s\n",result_std2);
// }
