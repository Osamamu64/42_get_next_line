/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:24:12 by oelshare          #+#    #+#             */
/*   Updated: 2022/10/20 01:05:12 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include    <stdlib.h>
# include    <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char			*get_next_line_bonus(int fd);
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