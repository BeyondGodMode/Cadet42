/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:25:40 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/26 14:32:30 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str != NULL)
		ft_strlcpy(str, s1, len + 1);
	return (str);
}

#include <stdio.h>
#include <string.h>

int	main()
{
	const char *original = "Hello, World!";
    
    // Using the standard strdup function
    char *duplicate_std = strdup(original);
    if (duplicate_std) {
        printf("Using strdup (Standard): %s\n", duplicate_std);
        free(duplicate_std);
    }

    // Implementing your own strdup function
    char *duplicate_custom = ft_strdup(original);
    if (duplicate_custom) {
        printf("Using my_strdup (Custom): %s\n", duplicate_custom);
        free(duplicate_custom);
    }

    return 0;
}