/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:43:32 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/15 19:13:00 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	if (c1 != 7 + 48 || c2 != 8 + 48 || c3 != 9 + 48)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = 48;
	c2 = 49;
	c3 = 50;
	while (c1 <= 55)
	{
		print_number(c1, c2, c3);
		c3++;
		if (c3 >= 58)
		{
			c2++;
			if (c2 >= 57)
			{
				c1++;
				c2 = c1 + 1;
			}
			c3 = c2 + 1;
		}
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
