/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 19:01:30 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map, game->map_height);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(SUCCESS);
}

void	exit_with_error(t_game *game, const char *message)
{
	if (message)
		ft_printf("Error: %s\n", message);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map, game->map_height);
	exit(FAILURE);
}

int	valid_name_map(const char *filename)
{
	int		len;
	char	*basename;
	int		lenber;

	len = ft_strlen(filename);
	basename = ft_strrchr(filename, '/');
	if (basename)
	{
		basename++;
		lenber = ft_strlen(basename);
		if (lenber > 4 && ft_strncmp(basename + lenber - 4, ".ber", 4) == 0)
			return (1);
	}
	else if (len > 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (ac != 2)
		return (ft_printf("Usage: ./so_long <map_file.ber>\n"), 1);
	if (!valid_name_map(av[1]))
		return (ft_printf("Invalid map file\n"), 1);
	if (!get_map_size(&game, av[1]) || !game.map_width
		|| !game.map_height || game.map_width < 3 || game.map_height < 3
		|| game.map_width > 100 || game.map_height > 100)
		return (ft_printf("Invalid map size\n"), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Failed to initialize MLX\n"), 1);
	if (!allocate_map_memory(&game, game.map_width, game.map_height))
		return (ft_printf("Failed to allocate memory for map\n"), 1);
	if (!load_map(&game, av[1]))
		cleanup_and_exit (&game, "Failed to load map");
	create_window(&game);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
