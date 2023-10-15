/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:58:34 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/15 12:39:08 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (*(s + len) == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char * empty = (char*)calloc(1, 1);
// 	const char *string = "tripouille";
//     char target = 'l';
//     // Using the standard strrchr function
//     char *result_std = strrchr(empty, 'V');
// 	char *result_std2 = ft_strrchr(empty, 'V');
// 	printf("Ori = %s\n",result_std);
// 	printf("ft = %s\n",result_std2);
// }