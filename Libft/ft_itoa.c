/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:16:13 by tsongtra          #+#    #+#             */
/*   Updated: 2023/09/25 11:25:48 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlen(int n)
{
	size_t	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

void	ft_reverse(char *str)
{
	size_t	len;
	size_t	i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*str;
	size_t		neg;
	size_t		len;
	size_t		i;

	len = getlen(n);
	num = n;
	neg = ft_isneg(num);
	if (neg == 1)
		num = -num;
	str = (char *)malloc((len + 1 + neg) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i++] = '0' + (num % 10);
		num /= 10;
	}
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_reverse(str);
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char	*str;
// 	int		size;

// 	str = ft_itoa(-58594);
//  	// size = get_last_malloc_size();
// 	printf("String = %s",str);
// 	// printf("size = %d",size);
// 	return (0);
// }
