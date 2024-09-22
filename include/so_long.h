#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "../libft/libft.h"

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
}               t_game;

int     init_game(t_game *game, char *map_file);
int     parse_map(t_game *game, char *filename);
void    render_map(t_game *game);
int     handle_keypress(int key, t_game *game);
void    exit_game(t_game *game);

#endif

// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;


// void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);


// void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

// #include "mlx/mlx.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <X11/X.h>
// #include <X11/keysym.h>

// typedef struct s_data
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// } t_data;#endif
// int on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;

// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (1);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
// 	if (!data.win_ptr)
// 		return (free(data.mlx_ptr), 1);

// 	// Register key release hook
// 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

// 	// Register destroy hook
// 	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

// 	// Loop over the MLX pointer
// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }