/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:59:35 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 23:27:40 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"
#include <unistd.h>
#include "write.h"
#include "nbr.h"

void	ft_print(int *nbr, int len, t_num *num, int *fl)
{
	if (nbr[len] == 0 && len == 0 && *fl == 0)
		write_zero(num);
	else if (nbr[len] < 20)
		write_digit(nbr[len], num, fl);
	else if (nbr[len] < 100)
	{
		write_ten(nbr[len], num, fl);
		write_digit(nbr[len] % 10, num, fl);
	}
	else if (nbr[len] < 1000)
	{
		write_hundred(nbr[len], num, fl);
		write_ten(nbr[len] % 100, num, fl);
		if (nbr[len] % 100 < 10)
			write_digit(nbr[len] % 10, num, fl);
	}
	if (len > 0 && nbr[len] != 0)
		write_power(len, num, fl);
}

int	*algo(int *nbr, int len, t_num *num)
{
	int	fl;
	int	i;

	fl = 0;
	i = 0;
	while (num[i].value)
	{
		if (len == ft_nbrlen(num[i++].key))
			fl = 1;
	}
	if (fl != 1)
		return (write(1, "Error\n", 6), NULL);
	fl = 0;
	while (--len >= 0)
		ft_print(nbr, len, num, &fl);
	write(1, "\n", 1);
	return (nbr);
}
