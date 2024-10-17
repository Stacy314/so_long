/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/14 00:01:31 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Функція для відображення одного елемента на карті
void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * TILE_SIZE, y * TILE_SIZE);
}

// Функція для відображення всієї карти
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->player_img_right = mlx_xpm_file_to_image(game->mlx,
			GOBLIN_R, &width, &height);
	if (!game->player_img_right)
		exit_with_error("Failed to load player_right texture");
	game->player_img_left = mlx_xpm_file_to_image(game->mlx,
			GOBLIN_L, &width, &height);
	if (!game->player_img_left)
		exit_with_error("Failed to load player_left texture");
	game->player_img = game->player_img_right;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	if (!game->wall_img)
		exit_with_error("Failed to load wall texture");
	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR, &width, &height);
	if (!game->floor_img)
		exit_with_error("Failed to load floor texture");
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			MANA, &width, &height);
	if (!game->collectible_img)
		exit_with_error("Failed to load collectible texture");
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
	if (!game->exit_img)
		exit_with_error("Failed to load exit texture");
}
