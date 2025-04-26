/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:35:11 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:40:09 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "is_valid.h"

void	print_map(int map[4][4]);
int		backtrack(int skycraper[4][4], int map[4][4], int row, int col);

int	solve(int skycraper[4][4], int map[4][4], int row, int col)
{
	int	value;

	value = 1;
	while (value <= 4)
	{	
		map[row][col] = value;
		if (backtrack(skycraper, map, row, col))
			return (1);
		map[row][col] = 0;
		value++;
	}
	return (0);
}

int	backtrack(int skycraper[4][4], int map[4][4], int row, int col)
{
	if (is_cell_valid(map, row, col))
	{
		if (row == 3 && col < 3)
		{
			if (solve(skycraper, map, 0, col + 1))
				return (1);
		}	
		else if (row == 3 && col == 3)
		{
			if (is_map_valid(skycraper, map, -1, -1))
			{
				print_map(map);
				return (1);
			}
		}
		else if (solve(skycraper, map, row + 1, col))
			return (1);
	}
	return (0);
}
