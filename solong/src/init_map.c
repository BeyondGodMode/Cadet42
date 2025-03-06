/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:11:10 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 18:12:44 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_input(int arc, char **arv, t_game *game)
{
	char	*filename;

	game->map_alloc = false;
	if (arc > 2)
	{
		ft_error_msg("Too many arguments", game);
	}
	if (arc < 2)
	{
		ft_error_msg("Map is missing.", game);
	}
	filename = ft_strrchr(arv[1], '/');
	if (!filename)
		filename = arv[1];
	else
		filename++;
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4) != 0
		|| ft_strlen(filename) == 4)
		ft_error_msg("Map file extension should be .ber \
		and filename should not be just .ber.", game);
}

void	ft_check_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map an empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map an empty line right at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map an empty line \
			right at the middle.", game);
		}
		i++;
	}
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map can't be open", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	if (game->map.rows == 0)
		ft_error_msg("empty maps", game);
	ft_check_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}
