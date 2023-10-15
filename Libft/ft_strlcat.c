/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:35:50 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/15 13:01:47 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = dstlen;
	i = 0;
	if (dstlen < size - 1 && size > 0)
	{
		while (src[i] != '\0' && dstlen + i < size - 1)
		{
			dst[j] = src [i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (dstlen >= size)
		dstlen = size;
	return (dstlen + srclen);
}
