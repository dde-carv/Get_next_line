/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:56:00 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/29 14:28:34 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FDOPEN + 1][BUFFER_SIZE + 1];
	char		*line;
	size_t		len;
	size_t		len1;
	int			nl;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	nl = 0;
	while (!nl && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer[fd]);
		len = 0;
		len1 = 0;
		while (buffer[fd][len])
		{
			if (nl)
				buffer[fd][len1++] = buffer[fd][len];
			if (buffer[fd][len] == '\n')
				nl = 1;
			buffer[fd][len++] = 0;
		}
	}
	return (line);
}

/* #include <stdio.h>
int main(void)
{
	int	fd[2];
	char	*line[2];

	fd[0] = open("lol.txt", O_RDONLY);
	fd[1] = open("lol2.txt", O_RDONLY);
	while ((line[0] = get_next_line(fd[0])) != NULL
	&& (line[1] = get_next_line(fd[1])) != NULL)
	{
		printf("%s", line[0]);
		printf("%s", line[1]);
		free(line[0]);
		free(line[1]);
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
} */
