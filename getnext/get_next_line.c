/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:58:08 by tsongtra          #+#    #+#             */
/*   Updated: 2024/02/16 10:25:25 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
}

