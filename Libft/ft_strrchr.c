/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:58:34 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/26 13:26:31 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)last);
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