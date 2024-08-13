/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:56:00 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/13 11:39:48 by dde-carv         ###   ########.fr       */
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

	if (BUFFER_SIZE <= 0)
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

/*
#include <stdio.h>
int main(void)
{
	int fd1 = open("lol.txt", O_RDONLY);
	int fd2 = open("lol2.txt", O_RDONLY);
	char *line1;
	char *line2;
	while ((line1 = get_next_line(fd1)) != NULL
	&& (line2 = get_next_line(fd2)) != NULL)
	{
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
	}
	printf("%c", '\n');
	close(fd1);
	close(fd2);
	return 0;
} */
