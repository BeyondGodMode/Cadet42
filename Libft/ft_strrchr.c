/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:58:34 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 10:12:42 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	if (c == '\0')
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			last = s;
		s++;
	}
	return ((char *)last);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	  const char *string = "Hello, World!";
//     char target = 'l';

//     // Using the standard strrchr function
//     char *result_std = strrchr(string, target);
// 	char *result_std2 = ft_strrchr(string, target);
// 	printf("Ori = %s\n",result_std);
// 	printf("ft = %s\n",result_std2);
// }