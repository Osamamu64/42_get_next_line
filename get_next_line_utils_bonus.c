/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelshare <oelshare@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:24:17 by oelshare          #+#    #+#             */
/*   Updated: 2022/10/20 01:05:32 by oelshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;

	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
		{
			return ((char *)(s + x));
		}
		x++;
	}
	if (c == '\0')
		return ((char *)(s + x));
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		*((char *)s + x) = 0;
		x++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	size_t			x;
	size_t			y;

	x = 0;
	y = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[x] != '\0')
	{
		join[y++] = s1[x++];
	}
	x = 0;
	while (s2[x] != '\0')
	{
		join[y++] = s2[x++];
	}
	join[y] = '\0';
	return (join);
}
