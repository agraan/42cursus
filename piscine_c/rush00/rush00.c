/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:00:48 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/19 14:47:20 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int x)
{
	int	col;

	ft_putchar('o');
	col = 2;
	while (col < x)
	{
		ft_putchar('-');
		col = col + 1;
	}
	if (x > 1)
		ft_putchar('o');
}

void	middle_line(int x)
{
	int	col;

	ft_putchar('|');
	col = 2;
	while (col < x)
	{
		ft_putchar(' ');
		col = col + 1;
	}
	if (x > 1)
		ft_putchar('|');
}

void	last_line(int x)
{
	int	col;

	ft_putchar('o');
	col = 2;
	while (col < x)
	{
		ft_putchar('-');
		col = col + 1;
	}
	if (x > 1)
		ft_putchar('o');
}

void	rush(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y && x > 0)
	{
		if (line == 1 && x > 0)
			first_line(x);
		else if (line > 1 && line < y)
			middle_line(x);
		else if (line == y)
			last_line(x);
		ft_putchar(10);
		line = line + 1;
	}
}
