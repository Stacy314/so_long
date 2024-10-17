/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/13 22:28:41 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
    free_map(game->map, game->map_height);
    mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
void	exit_with_error(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
	exit(1);
}

int	valid_name_map(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)    //5         // Розширення ".ber" має мінімум 4 символи
		return (0);
    // Перевіряємо, чи закінчується файл на ".ber"
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0) // 5
		return (1);
	return (0);
}

int main(int ac, char **av)
{
    t_game game;

    game.steps = 0;
    //ft_bzero(&game, sizeof(game));
    if (ac != 2)
        exit_with_error("Usage: ./so_long <map_file.ber>\n");

    if (!valid_name_map(av[1]))
			exit_with_error("Invalid map file. Must be a .ber file");

    // Ініціалізація MiniLibX
    game.mlx = mlx_init();
    if (game.mlx == NULL)
        exit_with_error("Failed to initialize MLX");

    // int fd = open("tets", O_RDONLY);
	// char *line = get_next_line(fd);
	// while (line)
	// {
	// 	printf("%s", line);
	// 	if (!line)
	// 		return 0;
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	// close(fd);
	// return 0;
    
    // Отримуємо розміри карти
    get_map_size(&game, av[1]);

    // Виділяємо пам'ять для карти
    allocate_map_memory(&game, game.map_width, game.map_height);


    // Завантаження та парсинг карти
    load_map(&game, av[1]);

    // Створюємо вікно потрібного розміру
    create_window(&game);
    
    load_images(&game);

    // Рендеринг початкового стану карти
    render_map(&game);

    // Обробка події закриття вікна
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_window, &game); // 17 — подія для закриття вікна

    // Запускаємо цикл подій MiniLibX
    mlx_loop(game.mlx);

    return (0);
}

