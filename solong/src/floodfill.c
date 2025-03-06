/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:21:18 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 16:22:02 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void validate_reachable_objects(t_game *game, int **visited)
{
    int y = 0;
    int x;

    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if ((game->map.full[y][x] == COINS || game->map.full[y][x] == MAP_EXIT) && visited[y][x] == 0)
            {
                ft_error_msg("Error: There is an unreachable coin or exit.", game);
            }
            x++;
        }
        y++;
    }
}

void flood_fill(char **map, int y, int x, int **visited, int rows, int cols)
{
    // ตรวจสอบขอบเขตของแผนที่
    if (x < 0 || x >= cols || y < 0 || y >= rows || visited[y][x] || map[y][x] == WALL)
        return;

    // ทำเครื่องหมายว่าเราได้เยี่ยมชมแล้ว
    visited[y][x] = 1;
	printf("Visited: (%d, %d)\n", y, x);

    // เรียก flood fill ต่อไปในทิศทางต่าง ๆ (ขึ้น, ลง, ซ้าย, ขวา)
	flood_fill(map, y + 1, x, visited, rows, cols);  // ลง
    flood_fill(map, y - 1, x, visited, rows, cols);  // ขึ้น
    flood_fill(map, y, x + 1, visited, rows, cols);  // ขวา
    flood_fill(map, y, x - 1, visited, rows, cols);  // ซ้าย
}

void init_visited(int **visited, int rows, int cols)
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
	int		**visited;
	int		i;
	int		j;

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
	flood_fill(game->map.full, game->map.player.y, game->map.player.x, visited, game->map.rows, game->map.columns);
	printf("Visited Map:\n");
    for (i = 0; i < game->map.rows; i++)
    {
        for (j = 0; j < game->map.columns; j++)
            printf("%d ", visited[i][j]);
        printf("\n");
    }
	validate_reachable_objects(game, visited);
	i = 0;
	while (i < game->map.rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
