#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <stdlib.h>


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

#endif