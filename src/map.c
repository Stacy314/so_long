/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 19:56:37 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	validate_symbols(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
				game->map[y][x] != 'C' && game->map[y][x] != 'P' &&
				game->map[y][x] != 'E')
				exit_with_error(game, "Invalid character found");
			x++;
		}
		y++;
	}
	return (1);
}

int	count_objects_on_map(t_game *game, int *collectibles, int *player_count,
	int *exit_count)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				(*collectibles)++;
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				(*player_count)++;
			}
			else if (game->map[y][x] == 'E')
				(*exit_count)++;
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int	collectibles;
	int	player_count;
	int	exit_count;

	collectibles = 0;
	player_count = 0;
	exit_count = 0;
	count_objects_on_map(game, &collectibles, &player_count, &exit_count);
	if (!validate_symbols(game))
		return (0);
	game->collectibles = collectibles;
	if (player_count != 1 || exit_count != 1 || collectibles < 1)
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_reachability(game))
		return (0);
	return (1);
}

int	allocate_map_memory(t_game *game, int width, int height)
{
	int	i;

	game->map = malloc(sizeof(char *) * (height + 1));
	if (!game->map)
		return (0);
	i = 0;
	while (i < height)
	{
		game->map[i] = malloc(sizeof(char) * (width + 1));
		if (!game->map[i])
			return (0);
		i++;
	}
	return (1);
}
