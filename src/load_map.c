/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:06 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/04 16:57:42 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	allocate_map_memory(t_game *game, int width, int height)
{
	int	i;

	game->map = ft_calloc(sizeof(char *) * (height + 1), 1);
	if (!game->map)
		return (0);
	i = 0;
	while (i < height)
	{
		game->map[i] = malloc(sizeof(char) * (width + 1));
		if (!game->map[i])
			return (0);
		i++;
	}
	return (1);
}

int	validate_row_length(const char *line, int expected_width)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length != expected_width)
		return (0);
	return (1);
}

int	process_map_line(t_game *game, char *line, int y)
{
	if (!validate_row_length(line, game->map_width))
		return (0);
	ft_strlcpy(game->map[y], line, game->map_width + 1);
	return (1);
}

int	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line && line != NULL)
	{
		if (!process_map_line(game, line, y))
		{
			free_remaining_lines(fd, line);
			exit_with_error(game, "Invalid map shape");
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	if (!validate_map(game))
		exit_with_error(game, "Invalid map");
	return (close(fd), 1);
}
