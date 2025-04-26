/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:42:08 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/23 13:54:40 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_correct(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len == 0 || base_len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned int	ft_base_len(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

unsigned int	convert(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	return ((unsigned int)nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nb;

	base_len = ft_base_len(base);
	if (!(base_correct(base, base_len)))
		return ;
	nb = convert(nbr);
	if (nb >= base_len)
	{	
		ft_putnbr_base(nb / base_len, base);
		ft_putchar(base[nb % base_len]);
	}
	if (nb < base_len)
	{
		ft_putchar(base[nb]);
	}
}
