#include "../include/so_long.h"

int parse_map(t_game *game, char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    // Тут код для парсингу карти з файлу
    close(fd);
    return (1);
}

int init_game(t_game *game, char *map_file)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
    if (!parse_map(game, map_file))
        return (0);
    // Інші ініціалізації
    return (1);
}