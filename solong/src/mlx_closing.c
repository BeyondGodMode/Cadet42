/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_closing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:41:02 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 10:27:42 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("Error %s\n", message);
	exit (EXIT_FAILURE);
}

int	ft_victory(t_game *game)
{
	ft_printf("\nMovements: %d\n", ++game->movements);
	ft_free_all(game);
	ft_printf("your wins!!\n");
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->movements);
	ft_free_all(game);
	ft_printf("CLOSED\n");
	exit (EXIT_FAILURE);
}
