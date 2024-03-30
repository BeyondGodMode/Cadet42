/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servcer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:18:39 by beyondq           #+#    #+#             */
/*   Updated: 2024/03/30 18:11:12 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

#define END_TRANMISSION '\0'

void handle_signal(int sig)
{
    static unsigned char    current_char;
    static int              bit_index;

    current_char |= (sig == SIGUSR1);
    bit_index++;
    if (bit_index == 8)
    {
        if (current_char == END_TRANMISSION)
            ft_putstr_fd("\n", 1);
        else
            ft_putchar_fd(current_char, 1);
        bit_index = 0;
        current_char = 0;
    }
    else
        current_char <<= 1;
}

int main(void)
{
    ft_putstr_fd("PID\n", 1);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while(1)
        pause();
    return (0);
}