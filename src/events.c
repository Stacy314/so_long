#include "../include/so_long.h"

int handle_keypress(int key, t_game *game)
{
    if (key == ESC_KEY)
        exit_game(game);
    else if (key == W_KEY)
        move_player(game, UP);
    else if (key == A_KEY)
        move_player(game, LEFT);
    else if (key == S_KEY)
        move_player(game, DOWN);
    else if (key == D_KEY)
        move_player(game, RIGHT);
    return (0);
}

void exit_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    free(game); // Не забувайте вільнити всі ресурси
    exit(0);
}