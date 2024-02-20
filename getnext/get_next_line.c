/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:58:08 by tsongtra          #+#    #+#             */
/*   Updated: 2024/02/20 19:17:25 by tsongtra         ###   ########.fr       */
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
	line = (char *) malloc ((i + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		printf("line %p\n",line);
		return (NULL);
	}
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

	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
	{
		free(str);
		str = NULL;
		printf("str ================= %p\n",str);
		return (NULL);
	}
	if (str[i] == '\n')
		i++;
	buff = (char *)malloc(1 + ft_strlen(str) - i);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
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
	tmp = (char *) malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!tmp)
	{
		free(tmp);
		tmp = NULL;
		printf("abc");
		return (NULL);
	}
	// printf("test string = %s\n",str);
	while (!(ft_strchr(str, '\n')) && fd_read > 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			// printf("str tester %s\n",str);
			free(tmp);
			free(str);
			str = NULL;
			return (NULL);
		}
		tmp[fd_read] = '\0';
		// printf("fd_read %i\n",fd_read);
		// printf("tmp %s\n",tmp);
		// printf("str %s\n",str);
		str = ft_strjoin(str, tmp);
		// printf("tmp %s\n",tmp);
	}
	free(tmp);
	tmp = ft_line(str);
	// printf("tmp2 = %s\n",tmp);
	str = get_next(str, 0, 0);
	printf("str2 = %p \n",str);
	printf("tmp2 = %p \n",tmp);
	return (tmp);
}

// int	main(void)
// {
// 	int	fd;
// 	char * line;

// 	fd = open("empty.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
	
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// }
