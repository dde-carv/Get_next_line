/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:36:57 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/12 14:33:58 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		len;
	size_t		len1;
	int		nl;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	nl = 0;
	while (!nl && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		len = 0;
		len1 = 0;
		while (buffer[len])
		{
			if (nl)
				buffer[len1++] = buffer[len];
			if (buffer[len] == '\n')
				nl = 1;
			buffer[len++] = 0;
		}
	}
	return(line);
}

/* #include <stdio.h>
int main(void)
{
	int fd = open("lol.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("%c", '\n');
	close(fd);
	return 0;
} */
