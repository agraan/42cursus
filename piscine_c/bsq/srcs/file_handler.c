/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:38:20 by babodere          #+#    #+#             */
/*   Updated: 2025/02/05 22:41:49 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	lines_len(int fd, int index, int n)
{
	char	buff[BUFF_SIZE];
	int		count;
	int		before_count;

	before_count = 0;
	count = 0;
	n = 1;
	while (n > 0)
	{
		index = -1;
		n = read(fd, buff, BUFF_SIZE);
		while (++index < n)
		{
			if (buff[index] == '\n')
			{
				if (before_count != 0 && count != before_count)
					return (-1);
				before_count = count;
				count = 0;
				index++;
			}
			count++;
		}
	}
	return (before_count);
}

int	get_first_line(int fd)
{
	char	buff;
	int		count;

	buff = 0;
	count = 0;
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
			break ;
		count++;
	}
	return (count);
}

char	*get_next_line(int fd, int line_len)
{
	char	*retval;
	char	buff;
	int		index;

	index = 0;
	retval = (char *) malloc(sizeof(char) * line_len + 1);
	if (!retval)
		return (NULL);
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
			break ;
		retval[index] = buff;
		index++;
	}
	retval[index] = '\0';
	return (retval);
}

int	file_correct(char *file)
{
	int		fd;
	char	*fl;
	int		fll;
	int		line_len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	fl = get_next_line(fd, 100);
	if (!fl)
		return (0);
	fll = ft_strlen(fl);
	line_len = lines_len(fd, 0, 0);
	close(fd);
	if (!map_correct(file, fl[fll - 3], fl[fll - 2])
		|| !is_char_correct(fl[fll - 1])
		|| !is_char_correct(fl[fll - 2])
		|| !is_char_correct(fl[fll - 3])
		|| ft_atoi(fl) <= 0 || line_len == -1
		|| !correct_chars(fl[fll - 1], fl[fll - 2], fl[fll - 3]))
		return (free(fl), 1);
	free(fl);
	return (0);
}

t_map	get_struct(char *file)
{
	t_map	map;
	int		fd;
	char	*first_line;
	int		first_line_len;
	int		line_len;

	fd = open(file, O_RDONLY);
	first_line = get_next_line(fd, 100);
	map.len = 0;
	map.lines = 0;
	map.empty = 0;
	map.obstacle = 0;
	map.full = 0;
	if (!first_line)
		return (map);
	first_line_len = ft_strlen(first_line);
	line_len = lines_len(fd, 0, 0);
	map.len = line_len;
	map.lines = ft_atoi(first_line);
	map.empty = first_line[first_line_len - 3];
	map.obstacle = first_line[first_line_len - 2];
	map.full = first_line[first_line_len - 1];
	free(first_line);
	close(fd);
	return (map);
}
