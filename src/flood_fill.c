/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 16:33:51 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


char **copy_map(char **map, int width, int height)
{
    (void)width;

    char **copy = malloc(sizeof(char *) * height);
    if (!copy)
        return NULL;  // Перевірка на помилку виділення

    for (int i = 0; i < height; i++)
    {
        copy[i] = ft_strdup(map[i]);  // Копіюємо кожен рядок
        if (!copy[i])  // Перевірка на помилку виділення
        {
            // Якщо виділення пам'яті не вдалося, звільняємо вже виділену пам'ять
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
    }
    return copy;
}

void free_map_copy(char **map, int height)
{
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);
}


void flood_fill(char **map, int x, int y, int width, int height)
{
    if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '1' || map[y][x] == 'F')
        return;

    // Позначаємо клітинку як відвідану
    map[y][x] = 'F';

    // Рекурсивно викликаємо flood fill для сусідніх клітинок
    flood_fill(map, x + 1, y, width, height);
    flood_fill(map, x - 1, y, width, height);
    flood_fill(map, x, y + 1, width, height);
    flood_fill(map, x, y - 1, width, height);
}

int check_reachability(t_game *game)
{
    // Копіюємо карту для flood fill, щоб не змінювати оригінальну
    char **map_copy = copy_map(game->map, game->map_width, game->map_height);
    if (!map_copy)  // Перевірка на помилку копіювання карти
    {
        printf("Error: Failed to copy map.\n");
        return 0;
    }

    // Запускаємо flood fill з позиції гравця
    flood_fill(map_copy, game->player_x, game->player_y, game->map_width, game->map_height);

    // Перевіряємо досяжність всіх предметів та виходу
    for (int y = 0; y < game->map_height; y++)
    {
        for (int x = 0; x < game->map_width; x++)
        {
            if (game->map[y][x] == 'C' && map_copy[y][x] != 'F')  // Якщо предмет недосяжний
            {
                ft_printf("Error: Collectible at (%d, %d) is not reachable.\n", x, y);
                free_map_copy(map_copy, game->map_height);
                return (0);
            }
            if (game->map[y][x] == 'E' && map_copy[y][x] != 'F')  // Якщо вихід недосяжний
            {
                ft_printf("Error: Exit at (%d, %d) is not reachable.\n", x, y);
                free_map_copy(map_copy, game->map_height);
                return (0);
            }
        }
    }

    // Звільняємо пам'ять для копії карти
    free_map_copy(map_copy, game->map_height);
    return (1);
}

