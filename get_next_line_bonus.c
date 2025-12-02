/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:00:53 by abait-el          #+#    #+#             */
/*   Updated: 2025/12/02 21:41:17 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdlib.h>

char	*gnl_strcut(char **s, char sep)
{
	char	*pos;
	char	*left;
	char	*right;

	if (!s || !*s)
		return (NULL);
	pos = gnl_strchr(*s, sep);
	if (!pos)
		return (NULL);
	left = malloc((pos - *s) + 2);
	if (!left)
		return (NULL);
	gnl_strlcpy(left, *s, (pos - *s) + 2);
	if (!*(pos + 1))
		right = NULL;
	else
		right = gnl_strdup(pos + 1);
	free(*s);
	*s = left;
	return (right);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total;
	char	*ptr;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = (char *)malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*get_next_line(int fd)
{
	static char	*rem[MAX_FDS];
	char		*line;
	char		*buf;
	int			bytes;

	if (fd < 0)
		return (NULL);
	buf = gnl_calloc((size_t)BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	line = rem[fd];
	while (!gnl_strchr(buf, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		line = gnl_strjoin(line, line != NULL, buf, NO);
		if (!line)
			break ;
	}
	free(buf);
	rem[fd] = gnl_strcut(&line, '\n');
	return (line);
}
