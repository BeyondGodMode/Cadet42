/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:36:59 by tsongtra          #+#    #+#             */
/*   Updated: 2023/08/25 09:45:52 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

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
// 	printf("%d",ft_strlen(t));
// }