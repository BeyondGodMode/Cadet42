/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:06:01 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/22 14:07:02 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char *string = "tripouille";
//     char target = 'W';
//     char *result_std = strchr(string, 'o' + 256);
// 	char *result_std2 = ft_strchr(string, 'o' + 256);

// 	printf("Ori = %s\n",result_std);
// 	printf("ft = %s\n",result_std2);
// 	printf("t = %s\n",string);
// }
