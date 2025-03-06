/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:32 by tsongtra          #+#    #+#             */
/*   Updated: 2025/03/05 08:58:56 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t print_type(va_list args, const char c)
{
    size_t length = 0;

    if (c == 'c')
    	length = print_char(va_arg(args, int));
    else if (c == 's')
        length = print_string(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        length = print_int(va_arg(args, int));
    else if (c == '%')
        length = print_percent();
    else if (c == 'x' || c == 'X')
        length = print_hex(va_arg(args, unsigned int), c);
    else if (c == 'p')
        length = print_pointer(va_arg(args, unsigned long));
    else if (c == 'u')
        length = print_uint(va_arg(args, unsigned int));

    return length;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	length;
	size_t	i;

	va_start(args, str);
	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' )
		{
			if (str[++i] != '%')
				length += print_type(args, str[i]);
			else
				length += print_percent();
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
// int	main(void)
// {
// 	size_t	text;
// 	size_t	text2;
// 	int n;
// 	long long a;
// 	n = 23233;
// 	a = 1998882;
// 	// printf("Test %zu\n",write(1, "0", 1));
// 	// write(1, 1 + "A", 1);
// }
