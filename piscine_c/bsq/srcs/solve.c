/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:31:00 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/05 23:28:08 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	if (c <= a && c <= b)
		return (c);
	return (0);
}

int	check_sqr(int **matrix, int j)
{
	if (matrix[1][j - 1] && matrix[0][j] && matrix[0][j - 1])
		return (min(matrix[1][j - 1], matrix[0][j], matrix[0][j - 1]));
	return (0);
}

void	next_array(int **matrix, int size)
{
	int	j;

	j = -1;
	while (++j < size)
		matrix[0][j] = matrix[1][j];
}

t_max	solve2(int **arr, t_max max, int i, t_map map)
{
	int		j;
	char	*str;

	j = -1;
	str = get_next_line(max.fd, map.len);
	if (!str)
		return (write(2, "map error\n", 10), max);
	while (++j < map.len)
	{
		if (str[j] == map.empty)
		{
			arr[1][j] = check_sqr(arr, j) + 1;
			if (arr[1][j] > max.val || (arr[1][j] == max.val && j < max.i))
			{
				max.val = arr[1][j];
				max.line = i;
				max.i = j;
			}
			else if (i == 0 || j == 0)
				arr[1][j] = 1;
		}
		else if (str[j] == map.obstacle)
			arr[1][j] = 0;
	}
	return (free(str), max);
}

t_max	solve(int **arr, t_map map, char *file, t_max max)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	free(get_next_line(fd, map.len));
	max.fd = fd;
	i = -1;
	while (++i < map.lines)
	{
		max = solve2(arr, max, i, map);
		next_array(arr, map.len);
	}
	close(fd);
	return (max);
}
