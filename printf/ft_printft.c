/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:32 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/22 11:23:02 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	printf("%s\n",str);
	printf("%.2f\n",va_arg(args, double));
	printf("%d",va_arg(args, int));
	return (0);
}

int	main(void)
{
	ft_printf("test",1.1,2,3);
}
