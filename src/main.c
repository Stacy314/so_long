/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 17:47:45 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
	game->player_img = NULL;
	game->player_img_right = NULL;
	game->player_img_left = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->steps = 0;
	game->flag_exit = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game(&game);
	ft_bzero(&game, sizeof(game));
	if (ac != 2)
		return (ft_putstr_fd("Error: Usage ./so_long <map_file.ber>\n", 2), 1);
	if (!valid_name_map(av[1]))
		return (ft_putstr_fd("Error: Invalid map file\n", 1), 2);
	if (!get_map_size(&game, av[1]) || !game.map_width
		|| !game.map_height || game.map_width < 3 || game.map_height < 3
		|| game.map_width > 60 || game.map_height > 30)
		return (ft_putstr_fd("Error: Invalid map size\n", 2), 1);
	if (!allocate_map_memory(&game, game.map_width, game.map_height))
		return (ft_putstr_fd("Error: Failed to allocate memory\n", 2), 1);
	if (!load_map(&game, av[1]))
		cleanup_and_exit (&game, "Failed to load map");
	game.mlx = mlx_init();
	if (!game.mlx)
		cleanup_and_exit (&game, "Failed to load map");
	create_window(&game);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	return (mlx_loop(game.mlx), 0);
}
