/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/02 22:01:13 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char **map, int width, int height)
{
	int		i;
	char	**copy;

	(void)width;
	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	flood_fill(t_map *map_data, int x, int y)
{
	if (x < 0 || x >= map_data->width || y < 0 || y >= map_data->height
		|| map_data->map[y][x] == '1' || map_data->map[y][x] == 'F')
		return ;
	map_data->map[y][x] = 'F';
	flood_fill(map_data, x + 1, y);
	flood_fill(map_data, x - 1, y);
	flood_fill(map_data, x, y + 1);
	flood_fill(map_data, x, y - 1);
}

char	**perform_flood_fill(t_game *game)
{
	t_map	map_data;

	map_data.map = copy_map(game->map, game->map_width, game->map_height);
	if (!map_data.map)
		return (NULL);
	map_data.width = game->map_width;
	map_data.height = game->map_height;
	flood_fill(&map_data, game->player_x, game->player_y);
	return (map_data.map);
}

int	check_items_and_exit(t_game *game, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C' && map_copy[y][x] != 'F')
				return (0);
			if (game->map[y][x] == 'E' && map_copy[y][x] != 'F')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_reachability(t_game *game)
{
	char	**map_copy;

	map_copy = perform_flood_fill(game);
	if (!map_copy)
		return (0);
	if (!check_items_and_exit(game, map_copy))
	{
		free_map(map_copy, game->map_height);
		return (0);
	}
	free_map(map_copy, game->map_height);
	return (1);
}
