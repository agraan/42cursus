/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:25:58 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:14:44 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_top(int map[4][4], int col, int num)
{
	int	row;
	int	max;
	int	count;

	row = 0;
	max = 0;
	count = 0;
	while (row < 4)
	{
		if (map[row][col] > max)
		{
			max = map[row][col];
			count++;
		}
		row++;
	}
	if (count != num)
		return (0);
	return (1);
}

int	check_col_down(int map[4][4], int col, int num)
{
	int	row;
	int	max;
	int	count;

	row = 3;
	max = 0;
	count = 0;
	while (row >= 0)
	{
		if (map[row][col] > max)
		{
			max = map[row][col];
			count++;
		}
		row--;
	}
	if (count != num)
		return (0);
	return (1);
}

int	check_row_left(int map[4][4], int row, int num)
{
	int	col;
	int	max;
	int	count;

	col = 0;
	max = 0;
	count = 0;
	while (col < 4)
	{
		if (map[row][col] > max)
		{
			max = map[row][col];
			count++;
		}
		col++;
	}
	if (count != num)
		return (0);
	return (1);
}

int	check_row_right(int map[4][4], int row, int num)
{
	int	col;
	int	max;
	int	count;

	col = 3;
	max = 0;
	count = 0;
	while (col >= 0)
	{
		if (map[row][col] > max)
		{
			max = map[row][col];
			count++;
		}
		col--;
	}
	if (count != num)
		return (0);
	return (1);
}
