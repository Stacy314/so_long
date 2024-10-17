/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/10 16:51:51 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


char **copy_map(char **map, int width, int height)
{
    int i;
    (void)width;

    char **copy = malloc(sizeof(char *) * height);
    if (!copy)
        return NULL;
    i = 0;
    while(i < height)
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
        i++;
    }
    return copy;
}

void flood_fill(char **map, int x, int y, int width, int height)
{
    if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '1' 
        || map[y][x] == 'F')
        return;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, width, height);
    flood_fill(map, x - 1, y, width, height);
    flood_fill(map, x, y + 1, width, height);
    flood_fill(map, x, y - 1, width, height);
}
char **perform_flood_fill(t_game *game)
{
    // Копіюємо карту для flood fill, щоб не змінювати оригінал
    char **map_copy = copy_map(game->map, game->map_width,
        game->map_height);
    if (!map_copy)
    {
        ft_printf("Error: Failed to copy map.\n");
        return NULL;
    }
    // Запускаємо flood fill з позиції гравця
    flood_fill(map_copy, game->player_x, game->player_y,
        game->map_width, game->map_height);
    return (map_copy);  // Повертаємо скопійовану карту після flood fill
}
int check_items_and_exit(t_game *game, char **map_copy)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            // Перевіряємо, чи предмет недосяжний
            if (game->map[y][x] == 'C' && map_copy[y][x] != 'F')
            {
                ft_printf("Error\nCollectible is not reachable.\n");
                return (0);
            }
            // Перевіряємо, чи вихід недосяжний
            if (game->map[y][x] == 'E' && map_copy[y][x] != 'F')
            {
                ft_printf("Error\nExit is not reachable.\n");
                return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int check_reachability(t_game *game)
{
    char **map_copy = perform_flood_fill(game);
    if (!map_copy)
        return (0);
    // Перевіряємо досяжність всіх предметів та виходу
    if (!check_items_and_exit(game, map_copy))
    {
        free_map(map_copy, game->map_height);
        return (0);
    }
    free_map(map_copy, game->map_height);
    return (1);  // Всі предмети і вихід досяжні
}

