/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:42:09 by aprigent          #+#    #+#             */
/*   Updated: 2025/02/02 23:20:08 by aprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"

void	ft_putstr(char *str);
int		atoi_key(char *str);
int		ft_strlen(char *str);

void	write_zero(t_num *num)
{
	int	i;

	i = 0;
	while (num[i].value)
	{
		if (0 == atoi_key(num[i].key))
		{
			ft_putstr(num[i].value);
			break ;
		}
		i++;
	}
}

void	write_digit(int nbr, t_num *num, int *fl)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return ;
	while (num[i].value)
	{
		if (nbr == atoi_key(num[i].key))
		{
			if (*fl)
				write(1, " ", 1);
			ft_putstr(num[i].value);
			(*fl)++;
			break ;
		}
		i++;
	}
}

void	write_ten(int nbr, t_num *num, int *fl)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return ;
	if (nbr >= 20)
		nbr = (nbr / 10) * 10;
	while (num[i].value)
	{
		if (nbr == atoi_key(num[i].key))
		{
			if ((*fl)++)
				write(1, " ", 1);
			ft_putstr(num[i].value);
			break ;
		}
		i++;
	}
}

void	write_hundred(int nbr, t_num *num, int *fl)
{
	int	i;

	i = 0;
	while (num[i].value)
	{
		if (100 == atoi_key(num[i].key))
		{
			write_digit(nbr / 100, num, fl);
			if (*fl)
				write(1, " ", 1);
			ft_putstr(num[i].value);
			(*fl)++;
			break ;
		}
		i++;
	}
}

void	write_power(int value, t_num *num, int *fl)
{
	int	i;

	i = 0;
	value = 3 * value + 1;
	while (num[i].value)
	{
		if (ft_strlen(num[i].key) == value)
		{
			if (*fl)
				write(1, " ", 1);
			ft_putstr(num[i].value);
			(*fl)++;
			break ;
		}
		i++;
	}
}
