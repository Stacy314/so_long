/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/04 11:22:23 by apechkov         ###   ########.fr       */
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

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (can_move(game, new_x, new_y))
		update_player_position(game, new_x, new_y);
}
