/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 17:56:32 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Функція для перевірки, чи карта оточена стінами
int	check_walls(t_game *game)
{
	int x;
	int y;

	// Перевіряємо перший і останній рядки
	for (x = 0; x < game->map_width; x++)
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (0);
	// Перевіряємо перший і останній стовпці
	for (y = 0; y < game->map_height; y++)
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return (0);
	return (1);
}

int validate_symbols(t_game *game)
{
    int x;
    int y;

    // Проходимо по кожному рядку і колонці
    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            // Якщо символ не є дозволеним ('1', '0', 'C', 'P', 'E'), виводимо помилку
            if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
                game->map[y][x] != 'C' && game->map[y][x] != 'P' &&
                game->map[y][x] != 'E')
            {
                ft_printf("Error\nInvalid character '%c' found at position (%d, %d)\n", game->map[y][x], x, y);
                exit(0);
            }
        }
    }
    return (1);
}


int	validate_map(t_game *game)
{
	int x;
	int y;
	int collectibles = 0;
    int player_count = 0;
    int exit_count = 0;

	for (y = 0; y < game->map_height; y++)
	{
		for (x = 0; x < game->map_width; x++)
		{
			if (game->map[y][x] == 'C')
				collectibles++;
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
                player_count++;
			}
			else if (game->map[y][x] == 'E')
                exit_count++;
		}
	}
    // Перевіряємо символи на карті
    if (!validate_symbols(game))
        return (0);

    game->collectibles = collectibles;
    // Перевіряємо кількість гравців і виходів
	if (player_count != 1 || exit_count != 1 || collectibles < 1)
		return (0);

    if (!check_walls(game))
        exit_with_error("The map must be surrounded by walls.");
    
    if (!check_reachability(game))
        exit_with_error("Not all items or the exit are reachable.");    
    return (1);
}

// Функція для завантаження карти з файлу
void	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		y;
	int line_length;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error("Can't open map file");
	y = 0;
	while ((line = get_next_line(fd)))
	{
		line_length = ft_strlen(line);
        if (line[line_length - 1] == '\n')
            line[line_length - 1] = '\0';
        ft_strlcpy(game->map[y], line, game->map_width + 1);
        free(line);
        y++;
	}
	if (!validate_map(game))
	{
    	free_map(game);
    	exit_with_error("Invalid map");
	}
}

void allocate_map_memory(t_game *game, int width, int height)
{
    int i;

    game->map = malloc(sizeof(char *) * height);
    if (!game->map)
        exit_with_error("Failed to allocate memory for map");
    for (i = 0; i < height; i++)
    {
        game->map[i] = malloc(sizeof(char) * (width + 1));
        if (!game->map[i])
            exit_with_error("Failed to allocate memory for map row");
    }
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

void create_window(t_game *game)
{
    int window_width = game->map_width * TILE_SIZE;  // Ширина вікна = кількість клітинок * розмір одного тайла
    int window_height = (game->map_height) * TILE_SIZE;  // Висота вікна = кількість рядків * розмір одного тайла

    game->win = mlx_new_window(game->mlx, window_width, window_height, "So Long");
    if (!game->win)
        exit_with_error("Failed to create window");
}

void free_map(t_game *game)
{
    int i;

    for (i = 0; i < game->map_height; i++)
        free(game->map[i]);
    free(game->map);
}
