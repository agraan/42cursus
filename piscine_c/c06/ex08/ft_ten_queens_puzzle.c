/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:09:39 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/30 17:33:03 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_board(int board[10][10])
{
	int		row;
	int		column;
	char	c;

	column = 0;
	while (column < 10)
	{
		row = 0;
		while (row < 10)
		{
			if (board[row][column])
			{
				c = row + '0';
				write(1, &c, 1);
			}
			row++;
		}
		column++;
	}
	write(1, "\n", 1);
}

int	is_valid(int board[10][10], int row, int column)
{
	int	i;
	int	j;

	j = column;
	while (j-- > 0)
	{
		if (board[row][j])
			return (0);
	}
	i = row;
	j = column;
	while (i-- > 0 && j-- > 0)
	{
		if (board[i][j])
			return (0);
	}
	while (column-- > 0 && ++row < 10)
	{
		if (board[row][column])
			return (0);
	}
	return (1);
}

int	solve(int board[10][10], int row, int column, int *total)
{
	if (row == 10)
		return (0);
	if (column == 10)
	{
		*total = *total + 1;
		print_board(board);
		board[row][column - 1] = 0;
		return (1);
	}
	if (is_valid(board, row, column))
	{
		board[row][column] = 1;
		if (solve(board, 0, column + 1, total))
		{
			board[row][column] = 0;
			return (1);
		}
		board[row][column] = 0;
		solve(board, row + 1, column, total);
	}
	else
		solve(board, row + 1, column, total);
	return (0);
}

void	create_board(int *total)
{
	int	board[10][10];
	int	row;
	int	column;

	column = 0;
	while (column < 10)
	{
		row = 0;
		while (row < 10)
		{
			board[row][column] = 0;
			row++;
		}
		column++;
	}
	row = 0;
	column = 1;
	while (row < 10)
	{
		board[row][0] = 1;
		solve(board, 0, column, total);
		board[row][0] = 0;
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	*total;
	int	result;

	result = 0;
	total = &result;
	create_board(total);
	return (*total);
}
