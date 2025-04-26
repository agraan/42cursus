/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:35:28 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/19 13:24:24 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != 0)
	{
		if (str[i] >= 32 && str[i] <= 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[(unsigned char)str[i] / 16]);
			ft_putchar(hex[(unsigned char)str[i] % 16]);
		}
		i++;
	}
}
