/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:18:39 by beyondq           #+#    #+#             */
/*   Updated: 2024/03/31 14:08:32 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

#define END_TRANSMISSION '\0'

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
	current_char |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			ft_putstr_fd("\n", 1);
		else
			ft_putchar_fd(current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	(void)info;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_putstr_fd("PID\n", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
