/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:17:15 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/15 13:20:51 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > s_len)
		len = 0;
	else if (len > (s_len - start))
		len = s_len - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	s += start;
	ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char	t[] = "Hello World!";
// 	char	*str = ft_substr(t, 6, 8);
// 	printf("Ft = %s",str);
// 	return (0);
// }
