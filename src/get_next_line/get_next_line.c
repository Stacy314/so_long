/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:28 by apechkov          #+#    #+#             */
/*   Updated: 2025/06/19 21:42:10 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:28 by apechkov          #+#    #+#             */
/*   Updated: 2024/11/08 17:38:47 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **full_str)
{
	int		new_line_len;
	char	*str;
	char	*temp;
	char	*newline;

	if (!full_str || !*full_str)
		return (NULL);
	newline = ft_strchr_gnl(*full_str, '\n');
	if (!newline)
		return (str = ft_strdup(*full_str), clean(full_str), str);
	else
	{
		new_line_len = newline - *full_str;
		str = ft_calloc(new_line_len + 2, sizeof(char));
		if (!str)
			return (clean(full_str), NULL);
		ft_strlcpy(str, *full_str, new_line_len + 1);
		temp = ft_strdup(*full_str + new_line_len + 1);
		clean(full_str);
		if (!temp)
			return (clean(&str), NULL);
		*full_str = temp;
	}
	return (str);
}

char	*read_to_buffer(int fd, char **str)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (clean(str), NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		clean(&buffer);
		clean(str);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		clean(&buffer);
		if (**str == '\0')
			return (clean(str), NULL);
		return (*str);
	}
	return (buffer);
}

char	*join_and_clean(char *str, char *buffer)
{
	char	*temp;

	temp = str;
	str = ft_strjoin(str, buffer);
	clean(&buffer);
	free(temp);
	return (str);
}

char	*read_and_join(int fd, char *str)
{
	char	*buffer;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		buffer = read_to_buffer(fd, &str);
		if (!buffer)
			return (NULL);
		if (buffer == str)
			return (str);
		str = join_and_clean(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (str)
			free (str);
		return (NULL);
	}
	str = read_and_join(fd, str);
	if (!str)
		return (clean(&str), NULL);
	line = ft_get_line(&str);
	if (!line)
		return (clean(&str), NULL);
	return (line);
}
