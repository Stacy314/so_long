/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 12:29:06 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width
		|| new_y < 0 || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	update_player_direction(t_game *game, int new_x)
{
	if (new_x > game->player_x)
		game->player_img = game->player_img_right;
	else if (new_x < game->player_x)
		game->player_img = game->player_img_left;
}

void	handle_collectibles_and_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("You win! All items collected!\n");
		close_window(game);
	}
}

void	update_tile_images(t_game *game, int new_x, int new_y)
{
	if (game->map[game->player_y][game->player_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, game->player_x * TILE, game->player_y * TILE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor_img, game->player_x * TILE, game->player_y * TILE);
	if (game->map[new_y][new_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, new_x * TILE, new_y * TILE);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, new_x * TILE, new_y * TILE);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	update_player_direction(game, new_x);
	handle_collectibles_and_exit(game, new_x, new_y);
	update_tile_images(game, new_x, new_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
}
