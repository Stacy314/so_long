#include "../include/so_long.h"

void render_map(t_game *game)
{
    int x, y;

    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            if (game->map[y][x] == '1')
                draw_wall(game, x, y);
            else if (game->map[y][x] == 'C')
                draw_collectible(game, x, y);
            // інші елементи
        }
    }
}
