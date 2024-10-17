/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/10 14:59:50 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int can_move(t_game *game, int new_x, int new_y)
{
    // Перевірка меж карти
    if (new_x < 0 || new_x >= game->map_width || new_y < 0 
		|| new_y >= game->map_height)
        return (0);
    // Перевірка, чи це не стіна
    if (game->map[new_y][new_x] == '1')
        return (0);
    // Якщо гравець рухається на вихід, перевіряємо чи всі предмети зібрані
    if (game->map[new_y][new_x] == 'E' && game->collectibles > 0)
    {
        ft_printf("Cannot exit yet! Collect all items first.\n");
        return (0);
    }
    return (1);  // Рух дозволений
}

void update_player_position(t_game *game, int new_x, int new_y)
{
    // Оновлюємо спрайт залежно від напряму
    if (new_x > game->player_x)  // Рух вправо
        game->player_img = game->player_img_right;
    else if (new_x < game->player_x)  // Рух вліво
        game->player_img = game->player_img_left;
    // Якщо гравець рухається на клітинку з предметом
    if (game->map[new_y][new_x] == 'C')
    {
        game->collectibles--;  // Зменшуємо кількість предметів
        game->map[new_y][new_x] = '0';  // Замість предмета ставимо підлогу
    }
    // Якщо гравець на виході і всі предмети зібрані
    if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
    {
        ft_printf("You win! All items collected!\n");
        close_window(game);  // Завершуємо гру
    }
    // Оновлюємо карту та позицію гравця
    game->map[game->player_y][game->player_x] = '0';  // Очищаємо стару позицію
    game->map[new_y][new_x] = 'P';  // Переміщуємо гравця на нову позицію
    // Очищаємо стару позицію і рендеримо гравця на новій позиції
    mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
    mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		new_x * TILE_SIZE, new_y * TILE_SIZE);
    // Оновлюємо координати гравця
    game->player_x = new_x;
    game->player_y = new_y;
    // Збільшуємо лічильник кроків
    game->steps++;
    ft_printf("Steps: %d\n", game->steps);
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
    // Перевіряємо, чи може гравець рухатися
    if (can_move(game, new_x, new_y))
    {
        // Оновлюємо позицію гравця, якщо рух дозволений
        update_player_position(game, new_x, new_y);
    }
}
