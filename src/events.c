/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/13 22:27:23 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
    //printf("Key pressed: %d\n", keycode);
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

// void	free_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map_height)
// 	{
// 		free(game->map[i]);
// 		i++;
// 	}
// 	free(game->map);
// }

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);  // Звільняємо кожен рядок карти
		i++;
	}
	free(map);  // Звільняємо сам масив
}

void	create_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;  // Ширина вікна = кількість клітинок * розмір одного тайла
    window_height = (game->map_height) * TILE_SIZE;  // Висота вікна = кількість рядків * розмір одного тайла
	game->win = mlx_new_window(game->mlx, window_width,
			window_height, "So Long");
	if (!game->win)
		exit_with_error("Failed to create window");
}

void allocate_map_memory(t_game *game, int width, int height)
{
    int i;

    game->map = malloc(sizeof(char *) * height);
    if (!game->map)
        exit_with_error("Failed to allocate memory for map");
    i = 0;
    while (i < height)
    {
        game->map[i] = malloc(sizeof(char) * (width + 1));  // +1 для нульового символу
        if (!game->map[i])
        {
            // Якщо не вдалося виділити пам'ять, звільняємо вже виділену пам'ять
            //free_map(game);
            exit_with_error("Failed to allocate memory for map row");
        }
        i++;
    }
}

// Функція для завантаження карти з файлу
void	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		y;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error("Can't open map file");
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		ft_strlcpy(game->map[y], line, game->map_width + 1);
	
		// Виводимо рядки карти для відладки
		//ft_printf("Map row %d: %s\n", y, game->map[y]);
		
		free(line);
		y++;
		line = get_next_line(fd); 
	}
	close(fd);
	if (!validate_map(game))
	{
		free_map(game->map, game->map_height);
		exit_with_error("Invalid map");
	}
}


