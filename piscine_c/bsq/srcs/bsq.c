/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:37:04 by babodere          #+#    #+#             */
/*   Updated: 2025/02/05 22:41:26 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	start(char *file)
{
	int		**matrix;
	t_map	map;
	t_max	max;

	if (file_correct(file))
		return (write(2, "map error\n", 10), -1);
	map = get_struct(file);
	matrix = malloc(sizeof(int *) * 2);
	if (!matrix)
		return (0);
	matrix[0] = malloc(sizeof(int) * map.len);
	if (!matrix[0])
		return (0);
	matrix[1] = malloc(sizeof(int) * map.len);
	if (!matrix[1])
		return (0);
	max.val = 0;
	max.line = 0;
	max.i = 0;
	max.fd = 0;
	print_map(file, map, solve(matrix, map, file, max));
	free(matrix[0]);
	free(matrix[1]);
	free(matrix);
	return (0);
}

char	*stdin_file(void)
{
	char	buff[BUFF_SIZE];
	int		fd;
	int		n;

	fd = open(FILE_NAME, O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		ft_strerr("map error\n");
		return (NULL);
	}
	while (1)
	{
		n = read(0, buff, BUFF_SIZE);
		write(fd, buff, n);
		if (n <= 0)
			break ;
	}
	close(fd);
	return (FILE_NAME);
}

int	main(int ac, char **av)
{
	int		i;
	char	*file;

	i = 0;
	if (ac == 1)
	{
		file = stdin_file();
		if (!file)
			return (0);
		start(file);
	}
	else
	{
		while (++i < ac)
		{
			file = av[i];
			start(file);
			if (ac != 2 && i != ac - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
