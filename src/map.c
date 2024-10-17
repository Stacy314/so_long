/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/14 14:06:27 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Функція для перевірки, чи карта оточена стінами
int	check_walls(t_game *game)
{
	int	x;
	int	y;

	// Перевіряємо перший і останній рядки
	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	// Перевіряємо перший і останній стовпці
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
				exit_with_error("Invalid character found");
			x++;
		}
		y++;
	}
	return (1);
}

int count_objects_on_map(t_game *game, int *collectibles, int *player_count, int *exit_count)
{
    int x;
    int y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            //ft_printf("Checking position (%d, %d): %c\n", x, y, game->map[y][x]);
            if (game->map[y][x] == 'C')
                (*collectibles)++;
            else if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                (*player_count)++;
                //ft_printf("Found player at (%d, %d). Total players: %d\n", x, y, *player_count);
            }
            else if (game->map[y][x] == 'E')
                (*exit_count)++;
            x++;
        }
        y++;
    }
    return (1);
}

int validate_map(t_game *game)
{
    int collectibles;
    int player_count;
    int exit_count;

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
        exit_with_error("The map must be surrounded by walls.");
    if (!check_reachability(game))
        exit_with_error("Not all items or the exit are reachable.");
    return (1);
}

void get_map_size(t_game *game, char *filename)
{
    int fd;
    char *line;

    game->map_width = 0;
    game->map_height = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit_with_error("Can't open map file");
    while ((line = get_next_line(fd)))
    {
        if (game->map_width == 0)
            game->map_width = ft_strlen(line);  // Ширина визначається за першим рядком
        game->map_height++;
        free(line);
    }
    close(fd);
}

