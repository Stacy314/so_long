#include "../include/so_long.h"

int parse_map(t_game *game, char *filename)
{
    int fd;
    // char *line; // Коментуємо або видаляємо цю змінну, поки не буде потрібна

    (void)game; // Додаємо це, щоб тимчасово ігнорувати попередження про невикористаний параметр

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    // Тут буде код для парсингу карти
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