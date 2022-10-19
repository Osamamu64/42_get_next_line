/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:48:02 by oelshare          #+#    #+#             */
/*   Updated: 2022/10/20 01:01:35 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include    <stdlib.h>
# include    <unistd.h>
# include    <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*reader(int fd, char *str, size_t buf);
char			*join_free(char *buffer, char *buff);
char			*after(char *buffer);
char			*line_out(char *buffer);

void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

size_t			ft_strlen(const char *s);

#endif