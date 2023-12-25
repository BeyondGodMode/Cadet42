/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:12:07 by tsongtra          #+#    #+#             */
/*   Updated: 2023/12/25 11:27:07 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	print_char(char c);
size_t	print_string(char *str);
size_t	print_int(int n);
size_t	print_percent(void);
size_t	print_hex(unsigned long n, unsigned int c);
size_t	print_pointer(unsigned long n);
size_t	print_uint(unsigned int n);
int		ft_printf(const char *str, ...);

#endif 