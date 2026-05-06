/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:15:55 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/04 08:08:53 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	unsigned char	*s1;

	ch = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (*s1 != '\0')
	{
		if (*s1 == ch)
			return ((char *)s1);
		s1++;
	}
	if (ch == '\0')
		return ((char *)s1);
	return (NULL);
}

char	*set_line(char **str_leftover)
{
	char	*line;
	char	*newline;
	size_t	len;
	char	*tmp;

	line = NULL;
	newline = ft_strchr(*str_leftover, '\n');
	if (!newline)
		return (NULL);
	len = newline - *str_leftover;
	line = ft_substr(*str_leftover, 0, len + 1);
	tmp = *str_leftover;
	*str_leftover = ft_strdup(newline + 1);
	free(tmp);
	return (line);
}

char	*end_of_file(char **str_leftover, int bytes_read)
{
	char	*line;

	if (bytes_read == 0)
	{
		if (*str_leftover && **str_leftover)
		{
			line = ft_strdup(*str_leftover);
			free(*str_leftover);
			*str_leftover = NULL;
			return (line);
		}
		free(*str_leftover);
		*str_leftover = NULL;
	}
	return (NULL);
}

char	*get_line_buffer(int fd, char **str_leftover, char *buffer)
{
	ssize_t	bytes_read;
	char	*line;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*str_leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(*str_leftover);
			*str_leftover = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = *str_leftover;
		*str_leftover = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	line = set_line(str_leftover);
	if (!line)
		return (end_of_file(str_leftover, bytes_read));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str_leftover;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str_leftover)
		str_leftover = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str_leftover), NULL);
	line = get_line_buffer(fd, &str_leftover, buffer);
	return (line);
}
