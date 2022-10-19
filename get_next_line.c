/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:07:18 by oelshare          #+#    #+#             */
/*   Updated: 2022/10/20 01:02:13 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// The join and free simply using the strjoin to concatenate
// the output and buffer that from the reader and then we are freeing buffer

char	*join_free(char *buffer, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	return (tmp);
}
//The after function basically delete the line from the buffer
// first by finding the len of the line and the handling the NULL
// and then deleting the line by len of file - len of firstline + 1
// then line == buffer a

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
// The line out take the line we want to return 
// if there is no line then we return null
// we go to the end of the line if there is no \n
// we malloc the size of line(x), then check if it equals the buffer
// then we replace the end of the line by \n if its \n or \0

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
// The reader function is simply reading the fd and the buffer
// then using malloc in case of output does not exist
// then using malloc for the buffer 
// then checking if the read returns -1 we free the buffer and return null
// then to assign the buffer bytes to 0 to handle the leaks
// then we use join and free function to join the output and buffer 
// lastly we are checking for the end of the line to break the loop

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
// Firstly, handle the errors of the fd, buffersize, and the read
// Secondly, read the file by the reader function and handle the NULL
// Thirdly, read the line from the file, and then we delete that line

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	size_t			buf;

	buf = BUFFER_SIZE;
	if (fd < 0 || fd > 1024 || buf <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = reader(fd, buffer, buf);
	if (!buffer)
		return (NULL);
	line = line_out(buffer);
	buffer = after(buffer);
	return (line);
}

/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//	We open the file and assign the returned file descriptor
//	to the fd variable in order to use it later:
//	Then we make sure the file was correctly opened:
//	And we close the file with the reference to its fd:

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}*/