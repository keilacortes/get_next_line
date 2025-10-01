/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:11:20 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/09/25 16:24:14 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *buffer;
    int         bytes_read;
    static char *save_rest;
    char        *line_read;
    char        *tmp;
    char        *nl_ptr;
    char        *next_line;
    int         len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (read(fd, buffer, 0) < 0)
    {
        free(buffer);
        return (NULL);
    }
    if (save_rest)
    {
        line_read = ft_strdup(save_rest);
        free(save_rest);
        save_rest = NULL;
    }
    else
    {
        line_read = ft_strdup("");
    }

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(line_read, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        tmp = ft_strjoin(line_read, buffer);
        free(line_read);
        line_read = tmp;
    }
    free(buffer);
    if (!line_read || line_read[0] == '\0')
    {
        free(line_read);
        return (NULL);
    }

    nl_ptr = ft_strchr(line_read, '\n');
    if (nl_ptr)
    {
        len = nl_ptr - line_read + 1;
        next_line = ft_substr(line_read, 0, len);
        save_rest = ft_strdup(line_read + len);
    }
    else
    {
        next_line = ft_strdup(line_read);
    }
    free(line_read);
    return (next_line);
}
