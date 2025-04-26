/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:58 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/15 15:13:58 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int number)
{
	ft_putchar(number / 10 + 48);
	ft_putchar(number % 10 + 48);
}

void	ft_print_comb2(void)
{
	int	left_number;
	int	right_number;

	left_number = 0;
	right_number = 1;
	while (left_number <= 98)
	{
		while (right_number <= 99)
		{
			print_number(left_number);
			ft_putchar(' ');
			print_number(right_number);
			if (left_number < 98 || right_number <= 98)
				write(1, ", ", 2);
			right_number++;
		}
		left_number++;
		right_number = left_number + 1;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
