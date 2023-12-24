/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:32 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/24 22:42:08 by tsongtra         ###   ########.fr       */
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
	else if (c == 'd' || c == 'i')
		length = print_int((int)args);
	else if (c == '%')
		length = print_percent();
	else if (c == 'x' || c == 'X')
		length = print_hex((unsigned int)args, c);
	else if (c == 'p')
		length = print_pointer((unsigned long)args);
	else if (c == 'u')
		length = print_uint((unsigned int)args);
	return (length);
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
				length += print_type(va_arg(args, void *), str[i]);
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
int	main(void)
{
	size_t	text;
	size_t	text2;
	int n;
	long long a;

	n = 23233;
	a = 1998882;
	// printf("Test %zu\n",write(1, "0", 1));
	// write(1, 1 + "A", 1);
	text = ft_printf("Char %c String %s Int %d percent %% hex %x ptr %p int %i uint %u\n",'t',"Hello",n,a,&a,8,-1);
	text2 = printf("Char %c String %s Int %d percent %% hex %llx ptr %p int %i uint %u\n",'t',"Hello",n,a,&a,8,-1);
	printf("Number ft_printf = %zu\n",text);
	printf("Number printf = %zu\n",text2);
}
