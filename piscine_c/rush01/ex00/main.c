/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:26:39 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/26 20:59:04 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	solve(int skycraper[4][4], int map[4][4], int row, int col);

void	error(void)
{
	write(1, "Error\n", 6);
}

void	initialize_value(int map[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	check_value(char *str, int skycraper[4][4])
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	j = 0;
	if (str[0] < '1' || str[0] > '4')
		return (0);
	while (++i < 31)
	{
		if (str[i] == 0)
			return (0);
		if (str[i] >= '1' && str[i] <= '4' && (i == 0 || str[i - 1] == ' '))
		{
			skycraper[j][k] = str[i] - '0';
			k++;
		}
		if (k == 4)
		{
			j++;
			k = 0;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	map[4][4];
	int	skycraper[4][4];

	if (argc != 2)
	{
		error();
		return (0);
	}
	skycraper[3][3] = -1;
	if (check_value(argv[1], skycraper) == 0)
	{
		error();
		return (0);
	}
	if (skycraper[3][3] == -1)
	{
		error();
		return (0);
	}
	initialize_value(map);
	if (solve(skycraper, map, 0, 0))
		return (1);
	error();
	return (0);
}
