#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        printf("Error\nUsage: ./so_long <map.ber>\n");
        return (1);
    }
    if (!init_game(&game, argv[1]))
    {
        printf("Error\nFailed to initialize game.\n");
        return (1);
    }
    mlx_loop(game.mlx);
    return (0);
}



// if (all_collectables_collected && exit_count == 1)
// 	return map_valid;
// if (on_wall)
// 	return map_invalid;
// if (on_collectable)
// 	collectables++;
// if (on_exit)
// 	exits++;
// replace_current_position_with_wall;
// if (one_of_the_four_adjacent_directions_is_possible)
// 	return map_valid;
// return map_invalid;



// #include "mlx/mlx.h"
// #include <stdlib.h>

// int main(void)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
// 	if (!win_ptr)
// 		return (free(mlx_ptr), 1);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// 	return (0);
// }



// #include "so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	//void	*mlx_win;

// 	mlx = mlx_init();
// 	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

