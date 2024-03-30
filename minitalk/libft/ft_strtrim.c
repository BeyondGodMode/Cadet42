/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:10:10 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/15 18:21:36 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcheck(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_charcheck(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charcheck(s1[end - 1], set))
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1 [start++];
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char	t[] = " Hello, World! ";
// 	char	set[] = " ";
// 	char	*trim = ft_strtrim(t, set);

// 	printf("String after strim := %s",trim);
// 	return (0);
// }
