/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:36:59 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/25 22:25:34 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

// #include <stdio.h>

// int	main()
// {
// 	char t[] = "test46";
// 	printf("%zu",ft_strlen(t));
// }