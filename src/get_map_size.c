/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/04 17:03:08 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_map_dimensions(t_game *game, int *line_length)
{
	if (game->map_width == 0)
		game->map_width = *line_length;
	game->map_height++;
	*line_length = 0;
}

int	read_map_file(t_game *game, int fd)
{
	char	buffer[2];
	int		line_length;
	int		bytes_read;

	line_length = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (buffer[0] == '\n')
			update_map_dimensions(game, &line_length);
		else
			line_length++;
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
			return (0);
	}
	if (line_length > 0)
		update_map_dimensions(game, &line_length);
	return (1);
}

int	get_map_size(t_game *game, char *filename)
{
	int	fd;

	game->map_width = 0;
	game->map_height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(game, "Can't open map file");
	if (!read_map_file(game, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
