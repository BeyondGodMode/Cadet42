/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:21:23 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/06 10:37:15 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	count;

	if (*str == '\0')
		return (0);
	i = 0;
	count = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
	*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		count = (count * 10) + (*str - '0');
		str++;
	}
	return (count * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	char t[] = "  \t\n ++124 + 3";
// 	int a = atoi(t);
// 	printf("%d\n",a);
// 	a = ft_atoi(t);
// 	printf("%d",a);
// }