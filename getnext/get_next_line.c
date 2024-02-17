/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:58:08 by tsongtra          #+#    #+#             */
/*   Updated: 2024/02/17 15:50:36 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10000

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	int			fd_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	tmp = (char *) malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		str = ft_strjoin(str, tmp);
		printf("%s", str);
	}
	free(tmp);
	return (tmp);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
}
