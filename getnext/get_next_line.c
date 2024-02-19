/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:58:08 by tsongtra          #+#    #+#             */
/*   Updated: 2024/02/19 11:25:43 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_line(char *str)
{
	int		i;
	char	*line;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str [i] == '\n')
		i++;
	line = (char *) malloc (i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next(char *str, int i, int j)
{
	char	*buff;

	// if (str[i] == '\0' || str[i + 1] == '\0')
	// {
	// 	free(str);
	// 	return (NULL);
	// }
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (str[i] == '\n')
		i++;
	buff = (char *)malloc(1 + ft_strlen(str) - i);
	if (!buff)
		return (NULL);
	while (str[i + j])
	{
		buff[j] = str[i + j];
		j++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

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
		printf("fd_read %i\n",fd_read);
		printf("tmp %s\n",tmp);
		// printf("str %s\n",str);
		str = ft_strjoin(str, tmp);
		// printf("tmp %s\n",tmp);
	}
	// printf("str = %s\n",str);
	free(tmp);
	tmp = ft_line(str);
	printf("tmp2 = %s\n",tmp);
	str = get_next(str, 0, 0);
	// free(str);
	printf("str2 = %s\n",str);
	return (tmp);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("res 1= %s",get_next_line(fd));
	printf("res 2= %s",get_next_line(fd));
	// printf("res 3= %s",get_next_line(fd));
	// printf("res 4= %s",get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}
