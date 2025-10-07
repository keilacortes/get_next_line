/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:11:20 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/07 17:31:47 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_line(char **save_rest)
{
	char	*line_read;

	if (*save_rest)
	{
		line_read = ft_strdup(*save_rest);
		free(*save_rest);
		*save_rest = NULL;
	}
	else
		line_read = ft_strdup("");
	return (line_read);
}

static char	*read_and_append(int fd, char *line_read)
{
	char	*buffer;
	int		bytes_read;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(line_read, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(line_read, buffer);
		free(line_read);
		line_read = tmp;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(line_read);
		return (NULL);
	}
	return (line_read);
}

static char	*extract_line_and_save_rest(char *line_read, char **save_rest)
{
	char	*nl_ptr;
	char	*next_line;
	int		len;

	nl_ptr = ft_strchr(line_read, '\n');
	if (nl_ptr)
	{
		len = nl_ptr - line_read + 1;
		next_line = ft_substr(line_read, 0, len);
		*save_rest = ft_strdup(line_read + len);
	}
	else
	{
		next_line = ft_strdup(line_read);
		*save_rest = NULL;
	}
	return (next_line);
}

static void	clean_save_rest(char **save_rest)
{
	if (*save_rest && (*save_rest)[0] == '\0')
	{
		free(*save_rest);
		*save_rest = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*save_rest;
	char		*line_read;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_read = init_line(&save_rest);
	line_read = read_and_append(fd, line_read);
	if (!line_read || line_read[0] == '\0')
	{
		free(line_read);
		if (save_rest)
		{
			free(save_rest);
			save_rest = NULL;
		}
		return (NULL);
	}
	next_line = extract_line_and_save_rest(line_read, &save_rest);
	free(line_read);
	clean_save_rest(&save_rest);
	return (next_line);
}
