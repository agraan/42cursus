/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <aprigent@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:49:25 by aprigent          #+#    #+#             */
/*   Updated: 2025/05/08 23:41:35 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*line;
	int			b;
	int			i;
	int			j;

	if (fd < 0 || fd > 1023)
		return (NULL);
	free((j = -1, line = NULL, b = BUFFER_SIZE, NULL));
	while (nl_index(buff[fd], b) == -1)
	{
		line = str_join(line, buff[fd], BUFFER_SIZE);
		b = read(fd, buff[fd], BUFFER_SIZE);
		if (clear(buff[fd], b) && (b < 0 || !line || (!b && !*line)))
			return (clear(buff[fd], 0), free(line), NULL);
	}
	i = nl_index(buff[fd], b);
	line = str_join(line, buff[fd], i);
	while (buff[fd][++j + i])
		buff[fd][j] = buff[fd][j + i];
	buff[fd][j] = 0;
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		char *temp = get_next_line(fd);
		while (temp)
		{
			printf("%s", temp);
			free(temp);
			temp = get_next_line(fd);
		}
		free(temp);
	}
}*/
