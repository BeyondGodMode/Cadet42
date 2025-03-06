/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:12:38 by beyondq           #+#    #+#             */
/*   Updated: 2025/03/06 10:28:38 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define WALL_XPM			"sprites/wall.xpm"
# define FLOOR_XPM			"sprites/Grass2.xpm"
# define COINS_XPM			"sprites/coin.xpm"
# define PLAYER_FRONT_XPM	"sprites/player/Front.xpm"
# define PLAYER_LEFT_XPM	"sprites/player/Left.xpm"
# define PLAYER_RIGHT_XPM	"sprites/player/Right.xpm"
# define PLAYER_BACK_XPM	"sprites/player/Back.xpm"
# define OPEN_EXIT_XPM		"sprites/Doors-open.xpm"
# define EXIT_CLOSED_XPM	"sprites/Doors-Close.xpm"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_check_input(int arc, char **arv, t_game *game);
int		ft_error_msg(char *message, t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_line(char *map, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_parameters(t_game *game);
void	ft_check_parameters(t_game *game);
char	*ft_strappend(char **s1, const char *s2);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_move(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);
int		ft_victory(t_game *game);
int		ft_close_game(t_game *game);
void	ft_free_all(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);

#endif
