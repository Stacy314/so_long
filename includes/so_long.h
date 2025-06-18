/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 16:52:59 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>

# define TILE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define SUCCESS 1
# define FAILURE 0

# define MANA "./assets/collectible.xpm"
# define GOBLIN_R "./assets/player_right.xpm"
# define GOBLIN_L "./assets/player_left.xpm"
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
	void	*player_img_right;
	void	*player_img_left;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		steps;
	int		flag_exit;
}				t_game;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

// game.c
void	move_player(t_game *game, int new_x, int new_y);
int		handle_keypress(int keycode, t_game *game);
void	create_window(t_game *game);
int		load_map(t_game *game, char *filename);

// map.c
int		get_map_size(t_game *game, char *filename);
int		validate_map(t_game *game);
int		allocate_map_memory(t_game *game, int width, int height);
int		process_map_line(t_game *game, char *line, int y);
int		valid_name_map(const char *filename);
int		validate_row_length(const char *line, int expected_width);	

// render.c
void	load_images(t_game *game);
void	render_map(t_game *game);
void	free_images(t_game *game);
void	cleanup_and_exit(t_game *game, const char *error_message);

// free.c
int		close_window(void *param);
void	exit_with_error(t_game *game, const char *message);
void	free_remaining_lines(int fd, char *line);
void	free_map(char **map, int height);

// flood_fill.c
int		check_reachability(t_game *game);
void	flood_fill(t_map *map_data, int x, int y);

// player.c
int		can_move(t_game *game, int new_x, int new_y);
void	update_player_position(t_game *game, int new_x, int new_y);

#endif
