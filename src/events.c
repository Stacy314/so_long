/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 17:52:36 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int handle_keypress(int keycode, t_game *game)
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

void	exit_with_error(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
	exit(1);
}
