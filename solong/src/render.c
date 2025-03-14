/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:25:15 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 18:10:39 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite(game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite(game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite(game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite(game, game->player_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, column
		* sprite.x, line * sprite.y);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == PLAYER)
		ft_render_player(game, y, x);
	else if (parameter == WALL)
		ft_render_sprite(game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite(game, game->floor, y, x);
	else if (parameter == COINS)
		ft_render_sprite(game, game->coins, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite(game, game->open_exit, y, x);
		else
		{
			if (game->map.player.x == x && game->map.player.y == y)
				ft_render_player(game, y, x);
			else
				ft_render_sprite(game, game->exit_closed, y, x);
		}
	}
}

void	ft_print_move(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_move(game);
	return (0);
}
