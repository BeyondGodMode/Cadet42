/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:24:49 by beyondq           #+#    #+#             */
/*   Updated: 2024/03/30 18:11:14 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void send_signal(int pid, unsigned char character)
{
    int             i;
    unsigned char   temp_char;

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

int main(int arc, char **arv)
{
    pid_t       serverpid;
    const char  *msg;
    int         i;

    if(arc != 3)
    {
        ft_putstr_fd("Error input : <pid> <message> need\n", 1);
        exit(0);
    }
    serverpid = ft_atoi(arv[1]);
    msg = arv[2];
    i = 0;
    while(msg[i])
        send_signal(serverpid, msg[i++]);
    send_signal(serverpid, '\0');
    return (0);
}