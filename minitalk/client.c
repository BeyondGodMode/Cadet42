/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:24:49 by beyondq           #+#    #+#             */
/*   Updated: 2024/03/31 14:02:16 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

void	handle_read_receipt(int signal)
{
	(void)signal;
}

int	main(int arc, char **arv)
{
	pid_t		serverpid;
	const char	*msg;
	int			i;

	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	if (arc != 3)
	{
		ft_putstr_fd("Error input : <pid> <message> need\n", 1);
		exit(0);
	}
	serverpid = ft_atoi(arv[1]);
	msg = arv[2];
	i = 0;
	while (msg[i])
		send_signal(serverpid, msg[i++]);
	send_signal(serverpid, '\0');
	return (0);
}
