/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 18:24:12 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <stdbool.h>

# define TILE_SIZE 16 //64
# define KEY_W 119 //13
# define KEY_A 97 //0
# define KEY_S 115 //1
# define KEY_D 100 //2
# define KEY_ESC 65307 //53

# define MANA "./assets/collectible.xpm"
# define GOBLIN "./assets/player.xpm"
# define WALL "./assets/wall.xpm"
# define EXIT "./assets/exit.xpm"
# define FLOOR "./assets/floor.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		steps;
	void	*wdw;
}				t_game;

// game.c
void	move_player(t_game *game, int new_x, int new_y);

// map.c
void	load_map(t_game *game, char *filename);
void	exit_with_error(char *error_message);
void	get_map_size(t_game *game, char *filename);
void	allocate_map_memory(t_game *game, int width, int height);
void	create_window(t_game *game);
void	free_map(t_game *game);

// events.c
int		handle_keypress(int keycode, t_game *game);
int		handle_exit(t_game *game);

// render.c
int		render(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);

// main.c
int		close_window(void *param);

// flood_fill.c
int		check_reachability(t_game *game);

#endif