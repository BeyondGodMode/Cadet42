/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:21:18 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 18:37:14 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_reachable_objects(t_game *game, int **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if ((game->map.full[y][x] == COINS
					|| game->map.full[y][x] == MAP_EXIT) && visited[y][x] == 0)
			{
				ft_error_msg("Error: There is an unreachable coin or exit.",
					game);
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, int y, int x, int **visited)
{
	char	**map;
	int		rows;
	int		cols;

	map = game->map.full;
	rows = game->map.rows;
    cols = game->map.columns;
	if (x < 0 || x >= cols || y < 0 || y >= rows || visited[y][x]
		|| map[y][x] == WALL)
		return ;
	visited[y][x] = 1;
	flood_fill(game, y + 1, x, visited);
	flood_fill(game, y - 1, x, visited);
	flood_fill(game, y, x + 1, visited);
	flood_fill(game, y, x - 1, visited);
}

void	init_visited(int **visited, int rows, int cols)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			visited[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	ft_check_path(t_game *game)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)malloc(game->map.rows * sizeof(int *));
	if (!visited)
		ft_error_msg("Memory allocation failed", game);
	while (i < game->map.rows)
	{
		visited[i] = (int *)malloc(game->map.columns * sizeof(int));
		if (!visited[i])
			ft_error_msg("Memory allocation failed", game);
		i++;
	}
	init_visited(visited, game->map.rows, game->map.columns);
	flood_fill(game, game->map.player.y, game->map.player.x, visited);
	validate_reachable_objects(game, visited);
	i = 0;
	while (i < game->map.rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
