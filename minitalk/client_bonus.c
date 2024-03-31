/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:44:17 by beyondq           #+#    #+#             */
/*   Updated: 2024/03/31 11:15:52 by beyondq          ###   ########.fr       */
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
	if (signal == SIGUSR1)
		ft_putstr_fd("Recieved bit 1\n", 1);
	else if (signal == SIGUSR2)
		ft_putstr_fd("Recieved bit 0\n", 1);
}

int	main(int arc, char **arv)
{
	pid_t serverpid;
	const char *msg;
	int i;

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