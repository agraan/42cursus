/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:17:54 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/05 21:16:03 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_2(int i, char *str, t_map map, t_max max)
{
	int	j;

	while (i < map.lines)
	{
		j = -1;
		str = get_next_line(max.fd, map.len);
		if (!str)
			return ;
		while (++j < map.len)
		{
			if (i <= max.line && i >= max.line - max.val + 1)
			{
				if (j <= max.i && j >= max.i - max.val + 1)
					ft_putchar(map.full);
				else
					ft_putchar(str[j]);
			}
			else
				ft_putchar(str[j]);
		}
		free(str);
		write(1, "\n", 1);
		i++;
	}
}

void	print_map(char *file, t_map map, t_max max)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_strerr("map error\n");
		return ;
	}
	i = 0;
	str = get_next_line(fd, map.len);
	if (!str)
		return ;
	free(str);
	max.fd = fd;
	print_2(i, str, map, max);
	close(fd);
}

char	*save_file(char *file, int bytes)
{
	char	*retval;
	char	buff[1];
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	retval = (char *) malloc(sizeof(char) * (bytes + 1));
	while (read(fd, buff, 1) > 0)
	{
		retval[i++] = buff[0];
	}
	retval[i] = '\0';
	close(fd);
	return (retval);
}
