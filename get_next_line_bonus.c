/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpleutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:15:07 by bpleutin          #+#    #+#             */
/*   Updated: 2023/08/17 12:23:48 by bpleutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_cut_line(char *str, char *line)
{
	char	*res;
	int		n;

	res = NULL;
	n = ft_strlen(str);
	if (!line || !line[n])
	{
		free(line);
		return (res);
	}
	if (line[n])
		res = ft_substr(line, n, ft_strlen(line) - n);
	free(line);
	return (res);
}

static char	*ft_read_line(int fd, char *line, char **res)
{
	char	*buffer;
	int		r;
	int		n;

	buffer = malloc(BUFFER_SIZE + 1);
	r = 1;
	while (r != 0 && !ft_strchr(line, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	n = 0;
	if (line && line[n] && !*res)
	{
		while (line[n] && line[n] != '\n')
			n++;
		*res = ft_substr(line, 0, n + 1);
	}
	else
		*res = NULL;
	line = ft_cut_line(*res, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= 1024)
		return (free(line[fd]), line[fd] = NULL, NULL);
	return (res = NULL, line[fd] = ft_read_line(fd, line[fd], &res), res);
}
