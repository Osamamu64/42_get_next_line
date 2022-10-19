/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:24:07 by oelshare          #+#    #+#             */
/*   Updated: 2022/10/20 01:02:40 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(char *buffer, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	return (tmp);
}

char	*after(char *buffer)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - x + 1), sizeof(char));
	x++;
	y = 0;
	while (buffer[x] != '\0')
		line[y++] = buffer[x++];
	free(buffer);
	return (line);
}

char	*line_out(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	if (buffer[x] == '\0')
		return (NULL);
	while (buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	line = ft_calloc(x + 2, sizeof(char));
	x = 0;
	while (buffer[x] != '\0' && buffer[x] != '\n')
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] != '\0' && buffer[x] == '\n')
		line[x++] = '\n';
	return (line);
}

char	*reader(int fd, char *output, size_t buf)
{
	char	*buffer;
	int		bytes;

	if (!output)
		output = ft_calloc(1, 1);
	buffer = ft_calloc(buf + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(output);
			return (NULL);
		}
		buffer[bytes] = 0;
		output = join_free(output, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (output);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*line;
	size_t			buf;

	buf = BUFFER_SIZE;
	if (fd < 0 || buf <= 0)
		return (NULL);
	buffer[fd] = reader(fd, buffer[fd], buf);
	if (!buffer[fd])
		return (NULL);
	line = line_out(buffer[fd]);
	buffer[fd] = after(buffer[fd]);
	return (line);
}
