/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:55:31 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 16:53:39 by beyondq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Invalid map no Coins!", game);
	else if (game->map.exit != 1)
		ft_error_msg("Invalid map Exit gate.", game);
	else if (game->map.players != 1)
		ft_error_msg("Invalid map player should be 1.", game);
}

void	ft_count_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Invalid map not expected map parameter.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Invalid map wall missing \
			from the first columns.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Invalid map wall missing \
			from the last columns.", game);
		i++;
	}
}

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.full[i]) != game->map.columns)
			ft_error_msg("Invalid map: inconsistent row length.", game);
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Invalid map wall missing \
			from the first row.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg("Invalid map wall missing \
			from the last row.", game);
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_parameters(game);
	ft_check_parameters(game);
	ft_check_path(game);
}
