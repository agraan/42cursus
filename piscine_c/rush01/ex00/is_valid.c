/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:56:23 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:42:33 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check_map.h"

int	is_col_valid(int map[4][4], int row, int col)
{
	int	test_value;

	test_value = map[row][col];
	while (col-- > 0)
	{
		if (test_value == map[row][col])
			return (0);
	}
	return (1);
}

int	is_row_valid(int map[4][4], int row, int col)
{
	int	test_value;

	test_value = map[row][col];
	while (row-- > 0)
	{
		if (test_value == map[row][col])
			return (0);
	}
	return (1);
}

int	is_cell_valid(int map[4][4], int row, int col)
{
	if (is_col_valid(map, row, col))
	{
		if (is_row_valid(map, row, col))
		{
			return (1);
		}
	}
	return (0);
}

int	is_map_valid(int skycraper[4][4], int map[4][4], int row, int col)
{
	int	check;

	check = 0;
	while (++col < 4)
		check += check_col_top(map, col, skycraper[0][col]);
	if (check != 4)
		return (0);
	col = -1;
	check = 0;
	while (++col < 4)
		check += check_col_down(map, col, skycraper[1][col]);
	if (check != 4)
		return (0);
	check = 0;
	while (++row < 4)
		check += check_row_left(map, row, skycraper[2][row]);
	if (check != 4)
		return (0);
	row = -1;
	check = 0;
	while (++row < 4)
		check += check_row_right(map, row, skycraper[3][row]);
	if (check != 4)
		return (0);
	return (1);
}
