/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:32 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/23 15:42:34 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_type(void *args, const char c)
{
	size_t	length;

	if (c == 'c')
		length = print_char((int)args);
	else if (c == 's')
		length = print_string((char *)args);
	else if (c == 'd')
		length = print_int((int)args);
	return (length);
}

size_t	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	length;
	size_t	i;
	char	c;

	va_start(args, str);
	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			length += print_type(va_arg(args, void *), str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}

int	main(void)
{
	size_t	text;
	size_t	text2;
	int n;

	n = 23233;
	text = ft_printf("Char %c String %s Int %d\n",'t',"Hello",n);
	text2 = printf("Char %c String %s Int %d\n",'t',"Hello",n);
	printf("Number ft_printf = %zu\n",text);
	printf("Number printf = %zu\n",text2);
}
