/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 19:50:27 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    // Перевірка меж карти
    if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
        return;

    // Перевірка, чи це не стіна
    if (game->map[new_y][new_x] == '1')
        return;

	// Якщо гравець рухається на клітинку з колекційним предметом
    if (game->map[new_y][new_x] == 'C')
    {
        game->collectibles--;  // Зменшуємо кількість предметів
        game->map[new_y][new_x] = '0';  // Замість предмета ставимо підлогу
        //printf("Collected an item! Remaining: %d\n", game->collectibles);
    }

	// Якщо гравець рухається на вихід
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->collectibles > 0)
        {
            ft_printf("Cannot exit yet! Collect all items first.\n");
            return ;
        }
        else
        {
            ft_printf("You win! All items collected!\n");
            close_window(game);
        }
    }
	// Оновлення позиції гравця
    game->map[game->player_y][game->player_x] = '0';  // Очищаємо стару позицію гравця
    game->map[new_y][new_x] = 'P';  // Переміщуємо гравця на нову позицію
    game->player_x = new_x;
    game->player_y = new_y;

    // Збільшуємо лічильник кроків
    game->steps++;

    // Виводимо кількість кроків
    ft_printf("Steps: %d\n", game->steps);

    // Очищаємо вікно перед рендерингом (щоб не залишалися старі спрайти)
    //mlx_clear_window(game->mlx, game->win);

    // Перемальовуємо всю карту
    render_map(game);
}
