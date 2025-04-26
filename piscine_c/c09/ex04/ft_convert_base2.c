/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:24:53 by aprigent          #+#    #+#             */
/*   Updated: 2025/01/31 22:57:01 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	base_correct(const char *base, int base_len)
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

int	ft_base_len(const char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long nbr, const char *base, char *str, int *i)
{
	int	base_len;

	base_len = ft_base_len(base);
	if (nbr < 0)
	{
		str[*i] = '-';
		nbr = -nbr;
		(*i)++;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base, str, i);
		str[*i] = base[nbr % base_len];
	}
	if (nbr < base_len)
	{
		str[*i] = base[nbr];
	}
	(*i)++;
}
