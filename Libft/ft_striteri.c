/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:49:38 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/24 14:34:36 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (*s)
			f(i++, s++);
	}
}

// #include <stdio.h>

// void	iterator_function(unsigned int index, char *c)
// {
// 	(*c)++;
// }

// int main()
// {
// 	char input[] = "hello";
// 	printf("Input: %s\n", input);
// 	// Applying the iterator function to modify the input string
// 	ft_striteri(input, iterator_function);
// 	printf("Modified String: %s\n", input);
// 	return (0);
// }
