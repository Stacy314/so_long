/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 21:11:32 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		move_player(game, 0, -1);
	if (keycode == KEY_A)
		move_player(game, -1, 0);
	if (keycode == KEY_S)
		move_player(game, 0, 1);
	if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	create_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE;
	window_height = game->map_height * TILE;
	game->win = mlx_new_window(game->mlx, window_width,
			window_height, "So Long");
	if (!game->win)
		exit_with_error(game, "Failed to create window");
}

int	validate_row_length(const char *line, int expected_width)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length != expected_width)
		return (0);
	return (1);
}

int	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line && line != NULL)
	{
		if (!validate_row_length(line, game->map_width))
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			free(line);
			close(fd);
			exit_with_error(game, "Error: Invalid map shape");
		}
		ft_strlcpy(game->map[y], line, game->map_width + 1);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	if (!validate_map(game))
		exit_with_error(game, "Invalid map");
	return (close(fd), 1);
}

//int	load_map(t_game *game, char *filename)
//{
//	int		fd;
//	char	*line;
//	int		y;
//	int		line_length;

//	fd = open(filename, O_RDONLY);
//	if (fd < 0)
//		return (0);
//	y = 0;
//	line = get_next_line(fd);
//	while (line)
//	{
//		line_length = ft_strlen(line);
//		if (line[line_length - 1] == '\n')
//			line[line_length - 1] = '\0';
//		ft_strlcpy(game->map[y], line, game->map_width + 1);
//		free(line);
//		y++;
//		line = get_next_line(fd);
//	}
//	close(fd);
//	if (!validate_map(game))
//		exit_with_error(game, "Invalid map");
//	return (1);
//}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (can_move(game, new_x, new_y))
		update_player_position(game, new_x, new_y);
}
