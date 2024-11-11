/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/04 11:45:01 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game)
{
	if (game->player_img_right)
		mlx_destroy_image(game->mlx, game->player_img_right);
	if (game->player_img_left)
		mlx_destroy_image(game->mlx, game->player_img_left);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor_img, x * TILE, y * TILE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * TILE, y * TILE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * TILE, y * TILE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * TILE, y * TILE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * TILE, y * TILE);
}

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

void	cleanup_and_exit(t_game *game, const char *error_message)
{
	if (error_message)
		ft_printf("Error: %s\n", error_message);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->player_img_left)
		mlx_destroy_image(game->mlx, game->player_img_left);
	if (game->player_img_right)
		mlx_destroy_image(game->mlx, game->player_img_right);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map, game->map_height);
	exit(EXIT_FAILURE);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->player_img_right = mlx_xpm_file_to_image(game->mlx,
			GOBLIN_R, &width, &height);
	if (!game->player_img_right)
		cleanup_and_exit(game, "Failed to load player_right texture");
	game->player_img_left = mlx_xpm_file_to_image(game->mlx,
			GOBLIN_L, &width, &height);
	if (!game->player_img_left)
		cleanup_and_exit(game, "Failed to load player_left texture");
	game->player_img = game->player_img_right;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	if (!game->wall_img)
		cleanup_and_exit(game, "Failed to load wall texture");
	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR, &width, &height);
	if (!game->floor_img)
		cleanup_and_exit(game, "Failed to load floor texture");
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			MANA, &width, &height);
	if (!game->collectible_img)
		cleanup_and_exit(game, "Failed to load collectible texture");
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
	if (!game->exit_img)
		cleanup_and_exit(game, "Failed to load exit texture");
}
